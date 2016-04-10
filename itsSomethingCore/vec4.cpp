#include "vec4.h"

namespace itsSomething
{
	namespace math
	{
		vec4::vec4()
		{
		};

		vec4::vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		};

		vec4& vec4::add(const vec4& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
			return *this;
		};
		vec4& vec4::subs(const vec4& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
			return *this;
		};
		vec4& vec4::mult(const vec4& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;
			return *this;
		};
		vec4& vec4::div(const vec4& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			this->w /= other.w;
			return *this;
		};

		vec4 operator+(vec4 lhs, const vec4& rhs)
		{
			return lhs.add(rhs);
		};

		vec4 operator-(vec4 lhs, const vec4& rhs)
		{
			return lhs.subs(rhs);
		};

		vec4 operator*(vec4 lhs, const vec4& rhs)
		{
			return lhs.mult(rhs);
		};

		vec4 operator/(vec4 lhs, const vec4& rhs)
		{
			return lhs.div(rhs);
		};

		void vec4::operator+=(const vec4& other)
		{
			this->add(other);
		};
		void vec4::operator-=(const vec4& other)
		{
			this->subs(other);
		};
		void vec4::operator*=(const vec4& other)
		{
			this->mult(other);
		};
		void vec4::operator/=(const vec4& other)
		{
			this->div(other);
		};

		bool vec4::operator==(const vec4& other)
		{
			return this->x == other.x  && this->y == other.y && this->z == other.z && this->w == other.w;
		}
		
		bool vec4::operator!=(const vec4& other)
		{
			return !(*this == other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vector)
		{
			return stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z <<  ", " << vector.w << ")";
		};

	}
}
