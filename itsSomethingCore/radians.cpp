#include "radians.h"
#define _USE_MATH_DEFINES
#include <cmath>

namespace itsSomething
{
	namespace math
	{
		static radians toRadians(degrees deg);

		radians::radians()
		{
			this->val = 0.0f;
		};
		radians::radians(float rads)
		{
			this->val = rads;
		};
		radians::radians(degrees degs)
		{
			toRadians(degs);
		}

		static radians toRadians(degrees deg)
		{
			return radians(deg.val * (M_PI/ 180));
		}
	}
}