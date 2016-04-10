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

		vec3 operator+(vec3 lhs, const vec3& rhs)
		{
			return lhs.add(rhs);
		};

		vec3 operator-(vec3 lhs, const vec3& rhs)
		{
			return lhs.subs(rhs);
		};

		vec3 operator*(vec3 lhs, const vec3& rhs)
		{
			return lhs.mult(rhs);
		};

		vec3 operator/(vec3 lhs, const vec3& rhs)
		{
			return lhs.div(rhs);
		};

		void vec3::operator+=(const vec3& other)
		{
			this->add(other);
		};
		void vec3::operator-=(const vec3& other)
		{
			this->subs(other);
		};
		void vec3::operator*=(const vec3& other)
		{
			this->mult(other);
		};
		void vec3::operator/=(const vec3& other)
		{
			this->div(other);
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
