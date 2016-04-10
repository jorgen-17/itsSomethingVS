#pragma once

#include <istream>

namespace itsSomething
{
	namespace math
	{
		struct vec3
		{
			float x, y, z;

			vec3();
			vec3(const float& x, const float& y, const float& z);

			vec3& add(const vec3& other); 
			vec3& subs(const vec3& other);
			vec3& mult(const vec3& other);
			vec3& div(const vec3& other);

			friend vec3 operator+(vec3 lhs, const vec3& rhs);
			friend vec3 operator-(vec3 lhs, const vec3& rhs);
			friend vec3 operator*(vec3 lhs, const vec3& rhs);
			friend vec3 operator/(vec3 lhs, const vec3& rhs);

			void operator+=(const vec3& other);
			void operator-=(const vec3& other);
			void operator*=(const vec3& other);
			void operator/=(const vec3& other);

			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);
			
			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		};
	}
}