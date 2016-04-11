#pragma once
#include "degrees.h"

namespace itsSomething
{
	namespace math
	{
		struct radians
		{
			float val;

			radians();
			radians(float rads);
			radians(degrees deg);

			static radians toRadians(degrees deg);
		};
	}
}