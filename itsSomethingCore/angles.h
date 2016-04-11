#pragma once

namespace itsSomething
{
	namespace math
	{
		/*struct radians;
		struct degrees;
		static radians convertToRadians(degrees deg);
		static degrees convertToDegrees(const radians& rads);*/

		//TODO figure out how to make there mutually dependent struct to compile
		//struct radians
		//{
		//	float val;

		//	radians()
		//	{
		//		this->val = 0.0f;
		//	}

		//	radians(degrees deg)
		//	{
		//		this->val = convertToRadians(deg);
		//	}


		//};

		//struct degrees
		//{
		//	float val;

		//	degrees()
		//	{
		//		this->val = 0.0f;
		//	};
		//	degrees(radians rads)
		//	{
		//		this->val = convertToDegrees(rads);
		//	};
		//};

		static float degreestToRadians(const float deg)
		{
			return deg;
		}
		static float radiansToDegrees(const float rads)
		{
			return rads;
		}
	}
}