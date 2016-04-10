#include "vec3.h"

namespace itsSomething
{
	namespace math
	{
		vec3::vec3()
		{
		};

		vec3::vec3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		};

		vec3& vec3::add(const vec3& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		};
		vec3& vec3::subs(const vec3& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		};
		vec3& vec3::mult(const vec3& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			return *this;
		};
		vec3& vec3::div(const vec3& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			return *this;
		};

		bool vec3::operator==(const vec3& other)
		{
			return this->x == other.x  && this->y == other.y && this->z == other.z;
		}
		
		bool vec3::operator!=(const vec3& other)
		{
			return !(*this == other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec3& vector)
		{
			return stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		};

	}
}
