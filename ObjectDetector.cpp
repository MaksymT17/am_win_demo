#include "ObjectDetector.h"
#include "ImagePair.h"
//#include <future>

// uncomment in case of threadpool usage
//#include "ThreadPool.hpp"

namespace am
{
	namespace analyze
	{
		namespace algorithm
		{
			using namespace am::common::types;
			using Pixels = std::vector<Pixel>;

			ObjectDetector::ObjectDetector(
				const size_t threads,
				std::shared_ptr<am::configuration::Configuration> &conf,
				std::shared_ptr<am::common::Logger> &logger)
				: BfsObjectDetector(threads, conf, logger) {}

			// Time dependent execution, if max calculation time exceeded calculation should
			// finalize processing, and show up collected objects(if found).
			ObjectRectangle bfs(const ImagePair &pair, MatrixU16 &visited, Pixels &toCheck,
								ObjectRectangle &object, ImageRowSegment row,
								std::chrono::steady_clock::time_point &startTime,
								const configuration::Configuration &conf)
			{
				auto timeNow = std::chrono::steady_clock::now();
				std::chrono::duration<double> calcDuration = timeNow - startTime;
				if (calcDuration.count() >= conf.CalculationTimeLimit)
				{
					/// todo: make Error notification about failed detection
					printf("Timelimit for calculation exceeded. Try to increase calculation "
						   "time in configuration.\n");
					return object;
				}
				Pixels nextCheck;

				for (auto &position : toCheck)
				{
					if (visited(position.rowId, position.colId) != common::CHANGE &&
						pair.getAbsoluteDiff(position.rowId, position.colId) >
							conf.AffinityThreshold)
					{
						visited(position.rowId, position.colId) = common::CHANGE;
						checkClosest(position.rowId, position.colId, nextCheck, object, row,
									 visited.getWidth(), conf.PixelStep);

						object.addPixel(position.rowId, position.colId);
					}
				}
				if (nextCheck.size())
					bfs(pair, visited, nextCheck, object, row, startTime, conf);

				return object;
			}

			std::vector<ObjectRectangle>
			startObjectsSearchInPair(const ImagePair &pair, const ImageRowSegment &row,
									 const configuration::Configuration &conf)
			{
				auto startTime = std::chrono::steady_clock::now();
				MatrixU16 changes(pair.getWidth(), pair.getHeight());

				std::vector<ObjectRectangle> resultList;
				// check all diffs on potential objects if change found -> run bfs,
				// to figure out how many pixels included in this object
				for (size_t rowId = row.start; rowId < row.end; rowId += conf.PixelStep)
				{
					for (size_t colId = 0; colId < pair.getWidth(); colId += conf.PixelStep)
					{
						auto timeNow = std::chrono::steady_clock::now();
						std::chrono::duration<double> duration = timeNow - startTime;
						if (duration.count() >= conf.CalculationTimeLimit)
						{
							/// todo: make Error notification about failed detection
							// mLogger->logInfo("Timelimit for calculation exceded, calculations
							// TimeLimit:%f", conf.CalculationTimeLimit);
							return resultList;
						}
						else if (pair.getAbsoluteDiff(rowId, colId) > conf.AffinityThreshold &&
								 changes(rowId, colId) != common::CHANGE)
						{
							// Pixels obj{{rowId, colId}};
							ObjectRectangle obj(rowId, colId);
							auto conns = checkConnections(rowId, colId, pair.getWidth(), row, conf.PixelStep);

							resultList.emplace_back(bfs(pair, changes, conns, obj, row, startTime, conf));
						}
					}
				}
				return resultList;
			}

			DescObjects ObjectDetector::getObjectsRects(ImagePair &pair)
			{
				const size_t rowHeight = pair.getHeight() / mThreadsCount;
				std::vector<std::vector<ObjectRectangle>> res;
				//std::vector<std::future<std::vector<ObjectRectangle>>> futures;
				mLogger->info("ObjectDetector::getObjectsRects pair threads:%d",
							  mThreadsCount);

				// threadpool could be replaced with std::async calls
				//ThreadPool pool;
				//for (size_t rowId = 0; rowId < mThreadsCount - 1; ++rowId)
				//{
					ImageRowSegment row{0, pair.getHeight() };
					res.emplace_back(startObjectsSearchInPair(pair, row, *mConfiguration));

					//futures.emplace_back(pool.run(std::bind(&startObjectsSearchInPair, pair, row, *mConfiguration)));
				//}

				//ImageRowSegment final_row{(mThreadsCount - 1) * rowHeight, pair.getHeight()};
				 //futures.emplace_back(std::async(std::launch::async, startObjectsSearchInPair,
					//pair, final_row, *mConfiguration));
				//futures.emplace_back(pool.run(std::bind(&startObjectsSearchInPair, pair, final_row, *mConfiguration)));
				//for (auto &e : futures)
				//{
				//	res.emplace_back(e.get());
				//}

				return createObjectRects(res, mConfiguration->MinPixelsForObject);
			}
		} // namespace algorithm
	}	  // namespace analyze
} // namespace am