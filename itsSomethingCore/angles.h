#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

namespace itsSomething
{
	namespace math
	{
		struct degrees
		{
			float val;

			degrees::degrees()
			{
				this->val = 0;
			};
			degrees::degrees(float deg)
			{
				this->val = deg;
			}
		};

		struct radians
		{
			float val;

			radians::radians()
			{
				this->val = 0.0f;
			};
			radians::radians(float rads)
			{
				this->val = rads;
			};
		};

		static degrees toDegrees(radians rads)
		{
			return degrees(rads.val * (180.0f / M_PI));
		};

		static radians toRadians(degrees deg)
		{
			return radians(deg.val * (M_PI / 180.0f));
		}
	}
}
