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
