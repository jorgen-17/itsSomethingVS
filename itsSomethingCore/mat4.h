#pragma once
#include <ostream>
#include <vector>
#include "vec3.h"

namespace itsSomething
{
	namespace math
	{
		#define MAX_MAT4_INDEX 4 * 4
		
		struct  mat4
		{
			//elements indexed in column-major order
			std::vector<float> elements;

			mat4();
			mat4(float diagonal);

			static mat4 identity();
			static mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
			static mat4 perspective(float fov, float aspectRatio, float near, float far);
			static mat4 translation(static vec3& translation);
			static mat4 rotation(float angle, static vec3& axis);
			static mat4 scale(static vec3& scale);
			inline static int getRowIndex(int index) { return index % 4; };
			inline static int getColIndex(int index) { return index / 4; };

			mat4& multiply(const mat4& other);
			float getElementAt(int row, int col) const;

			friend mat4 operator*(mat4 lhs, const mat4& rhs);

			void operator*=(const mat4& other);

			bool operator==(const mat4& other);
			bool operator!=(const mat4& other);

			friend std::ostream& operator<<(std::ostream& stream, const mat4& vector);
		};
	}
}
