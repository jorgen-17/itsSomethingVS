#pragma once
#include "radians.h"

namespace itsSomething
{
	namespace math
	{
		struct radians;

		struct degrees
		{
			float val;

			degrees();
			degrees(float deg);
			degrees(radians rads);

			static degrees toDegrees(radians rads);
		};
	}
}