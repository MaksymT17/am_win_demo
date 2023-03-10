#pragma once

#include <memory>
#include "Matrix.hpp"
#include "Color24bDiff.hpp"
#include "ObjectRectangle.h"

namespace am
{
	namespace analyze
	{
		namespace algorithm
		{

			class ImagePair;

			// interface for Object properties extraction
			// pair of images is a minimal requirement for collecting objects
			class IObjectDetector
			{
			public:
				virtual ~IObjectDetector() = default;

				virtual DescObjects getObjectsRects(ImagePair &pair) = 0;
			};
		}
	}
}