#include "vec2.h"

namespace itsSomething
{
	namespace math
	{
		vec2::vec2()
		{
		};

		vec2::vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		};

		vec2& vec2::add(const vec2& other)
		{
			this->x += other.x;
			this->y += other.y;
			return *this;
		};
		vec2& vec2::subs(const vec2& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			return *this;
		};
		vec2& vec2::mult(const vec2& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			return *this;
		};
		vec2& vec2::div(const vec2& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			return *this;
		};

		vec2 operator+(vec2 lhs, const vec2& rhs)
		{
			return lhs.add(rhs);
		};

		vec2 operator-(vec2 lhs, const vec2& rhs)
		{
			return lhs.subs(rhs);
		};

		vec2 operator*(vec2 lhs, const vec2& rhs)
		{
			return lhs.mult(rhs);
		};

		vec2 operator/(vec2 lhs, const vec2& rhs)
		{
			return lhs.div(rhs);
		};

		void vec2::operator+=(const vec2& other)
		{
			this->add(other);
		};
		void vec2::operator-=(const vec2& other)
		{
			this->subs(other);
		};
		void vec2::operator*=(const vec2& other)
		{
			this->mult(other);
		};
		void vec2::operator/=(const vec2& other)
		{
			this->div(other);
		};

		bool vec2::operator==(const vec2& other)
		{
			return this->x == other.x  && this->y == other.y;
		}
		
		bool vec2::operator!=(const vec2& other)
		{
			return !(*this == other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec2& vector)
		{
			return stream << "vec2: (" << vector.x << ", " << vector.y << ")";
		};

	}
}
