#pragma once

#include <istream>

namespace itsSomething
{
	namespace math
	{
		struct vec2
		{
			float x, y;

			vec2();
			vec2(const float& x, const float& y);

			vec2& add(const vec2& other); 
			vec2& subs(const vec2& other);
			vec2& mult(const vec2& other);
			vec2& div(const vec2& other);

			friend vec2 operator+(vec2 lhs, const vec2& rhs);
			friend vec2 operator-(vec2 lhs, const vec2& rhs);
			friend vec2 operator*(vec2 lhs, const vec2& rhs);
			friend vec2 operator/(vec2 lhs, const vec2& rhs);

			void operator+=(const vec2& other);
			void operator-=(const vec2& other);
			void operator*=(const vec2& other);
			void operator/=(const vec2& other);

			bool operator==(const vec2& other);
			bool operator!=(const vec2& other);
			
			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
		};
	}
}