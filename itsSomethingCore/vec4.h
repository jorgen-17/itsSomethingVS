#pragma once

#include <istream>

namespace itsSomething
{
	namespace math
	{
		struct vec4
		{
			float x, y, z, w;

			vec4();
			vec4(const float& x, const float& y, const float& z, const float& w);

			vec4& add(const vec4& other); 
			vec4& subs(const vec4& other);
			vec4& mult(const vec4& other);
			vec4& div(const vec4& other);

			friend vec4 operator+(vec4 lhs, const vec4& rhs);
			friend vec4 operator-(vec4 lhs, const vec4& rhs);
			friend vec4 operator*(vec4 lhs, const vec4& rhs);
			friend vec4 operator/(vec4 lhs, const vec4& rhs);

			void operator+=(const vec4& other);
			void operator-=(const vec4& other);
			void operator*=(const vec4& other);
			void operator/=(const vec4& other);


			bool operator==(const vec4& other);
			bool operator!=(const vec4& other);
			
			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
		};
	}
}