#include "degrees.h"
#define _USE_MATH_DEFINES
#include <cmath>

namespace itsSomething
{
	namespace math
	{
		static degrees toDegrees(radians rads);

		degrees::degrees()
		{
			this->val = 0;
		};
		degrees::degrees(float deg)
		{
			this->val = deg;
		}
		degrees::degrees(radians rads)
		{
			toDegrees(rads);
		}

		static degrees toDegrees(radians rads)
		{
			return degrees(rads.val * (180 / M_PI));
		};
	}
}