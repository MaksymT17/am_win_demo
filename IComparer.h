#pragma once

#include <memory>
#include "Matrix.hpp"
#include "Color24bDiff.hpp"

namespace am
{
	namespace analyze
	{
		class IComparer
		{
		public:
			virtual ~IComparer() = default;
		};
	}
}
