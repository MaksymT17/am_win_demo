
#pragma once

#include <string>
#include <memory>
#include "Matrix.hpp"
#include "Color24b.hpp"

namespace am
{
	namespace extraction
	{
		class IExtractor
		{
		public:
			virtual ~IExtractor() = default;

			virtual common::types::Matrix<common::types::Color24b> readFile(std::string &filePath) = 0;
		};
	}
}
