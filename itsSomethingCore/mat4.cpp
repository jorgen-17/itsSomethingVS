#include "mat4.h"
#include <cassert>
#include <sstream>
#include <iomanip>
#include <math.h>

#define _USE_MATH_DEFINES

namespace itsSomething
{
	namespace math
	{
		mat4::mat4()
		{
			this->elements = std::vector<float>(MAX_MAT4_INDEX);
		};
		mat4::mat4(float diagonal)
		{
			this->elements = std::vector<float>(MAX_MAT4_INDEX);
			
			this->elements[0 + 0 * 4] = diagonal;
			this->elements[1 + 1 * 4] = diagonal;
			this->elements[2 + 2 * 4] = diagonal;
			this->elements[3 + 3 * 4] = diagonal;
		};

		static mat4 identity()
		{
			return mat4(1.0f);
		};
		static mat4 orthographic(float left, float right, float top, float bottom, float near, float far)
		{
			mat4 result;
			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);
			result.elements[3 + 3 * 4] = 1.0f;
			result.elements[0 + 3 * 4] = (left + right) / (left - right);
			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		};
		static mat4 perspective(float fov, float aspectRatio, float near, float far)
		{
			assert(far > near);

			
			mat4 result;
			result.elements[0 + 0 * 4] = 2.0f;
			result.elements[1 + 1 * 4] = 2.0f ;
			result.elements[2 + 2 * 4] = 2.0f / (near - far);
			result.elements[3 + 2 * 4] = 1.0f;

			return result;
		};
		static mat4 translation(static vec3& translation)
		{

		};
		static mat4 rotation(float angle, static vec3& axis)
		{

		};
		static mat4 scale(static vec3& scale)
		{

		};

		mat4& mat4::multiply(const mat4& other)
		{
			std::vector<float> results(MAX_MAT4_INDEX);
			for (int i = 0; i < MAX_MAT4_INDEX; i++)
			{
				auto result = 0.0f;
				auto row = getRowIndex(i);
				auto col = getColIndex(i);
				for (int j = 0; j < 4; j++)
				{
					result += (this->getElementAt(row, j) * other.getElementAt(j, col));
				}

				results[i] = result;
			}
			this->elements = results;

			return *this;
		};
		float mat4::getElementAt(int row, int col) const
		{
			assert(row >= 0 && row < 4 && col >= 0 && col < 4);
			auto index = (4 * col) + row;
			return this->elements[index];
		};

		mat4 operator*(mat4 lhs, const mat4& rhs)
		{
			return lhs.multiply(rhs);
		};

		void mat4::operator*=(const mat4& other)
		{
			this->multiply(other);
		};
		
		bool mat4::operator==(const mat4& other)
		{
			return this->elements == other.elements;
		};
		bool mat4::operator!=(const mat4& other)
		{
			return !(*this == other);
		};

		std::ostream& operator<<(std::ostream& stream, const mat4& matrix)
		{
			std::ostringstream outString;
			outString << "mat4: [" << std::endl;
			for (int row = 0; row < 4; row++)
			{
				outString << "\t";
				for (int col = 0; col < 4; col++)
				{
					std::string maybeComma = (row == 3 && col == 3) ? "" : ", ";
					outString << std::fixed << std::setprecision(2) << matrix.getElementAt(row, col) << maybeComma;
				}
				outString << std::endl;
					
			}
			outString << "\t]";

			return stream << outString.str();
		};
	}
}
