#include "window.h"
#include <iostream>
#include "math.h"

int main()
{
	using namespace itsSomething;

	graphics::window win("itsSomething!", 800, 600);
	glClearColor(0.1f, 0.9f, 0.1f, 1.0f);
	std::cout << glGetString(GL_VERSION) << std::endl;

	//testing out vec2
	//auto vector1 = math::vec2(1, 1);
	//auto vector2 = math::vec2(2, 2);
	//auto vector3 = math::vec2(1, 1);

	//std::cout << vector1 << std::endl;
	//std::cout << (vector1 == vector2) << std::endl;
	//std::cout << (vector1 != vector2) << std::endl;
	//std::cout << (vector1 == vector3) << std::endl;


	//std::cout << vector1 + vector2 << std::endl;
	//std::cout << vector1  << std::endl;

	//auto vector4 = vector2 + vector3;

	//std::cout << vector4 << std::endl;

	//vector4 += vector1;

	//std::cout << vector4 << std::endl;
	//std::cout << vector1 << std::endl;


	//testingout mat4
	math::mat4 mat1;
	mat1.elements = std::vector<float>{ 1,5,9,13,2,6,10,14,3,7,11,15,4,8,12,16 };
	math::mat4 mat2;
	mat2.elements = std::vector<float>{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
		//TODO: find out why this doesnt work: math::mat4::identity();

	std::cout << mat1 << std::endl;
	std::cout << mat2 << std::endl;
	mat1 *= mat2;
	std::cout << mat1 << std::endl;

	math::mat4 mat3(1.0f);
	math::mat4 mat4(1.0f);

	std::cout << (mat3 == mat4) << std::endl;
	std::cout << (mat3 == mat1) << std::endl;
	std::cout << (mat3 != mat4) << std::endl;



	while(!win.closed())
	{
		win.clear();
		
		if(win.isKeyPressed(GLFW_KEY_A))
		{
			std::cout << "pressed A" << std::endl;
		}

		if (win.isMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
		{
			std::cout << "Clicked" << std::endl;
		}

		//std::cout << win.getMouseX() << ", " << win.getMouseY() << std::endl;

		glBegin(GL_QUADS);
		glVertex2f(-0.25f, -0.25f);
		glVertex2f(-0.25f, 0.25f);
		glVertex2f(0.25f, 0.25f);
		glVertex2f(0.25f, -0.25f);
		glEnd();

		win.update();
	}

	return 0;
}	