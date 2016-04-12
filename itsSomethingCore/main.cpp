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
	math::mat4 matrix1;
	matrix1.elements = std::vector<float>{ 1,5,9,13,2,6,10,14,3,7,11,15,4,8,12,16 };
	math::mat4 matrix2;
	matrix2.elements = std::vector<float>{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
		//TODO: find out why this doesnt work: math::mat4::identity();

	std::cout << matrix1 << std::endl;
	std::cout << matrix2 << std::endl;
	matrix1 *= matrix2;
	std::cout << matrix1 << std::endl;
	auto identity = math::mat4::identity();
	auto maybeOne = (matrix1 == (matrix1 * identity));
	auto yesOrNoMessage = maybeOne ? "\tYayyyy!!!!" : "\tnoooo, why did you break it?!?!?!?";
	std::cout << "please be one: " << maybeOne << yesOrNoMessage << std::endl;

	math::mat4 matrix3(1.0f);
	math::mat4 matrix4 = math::mat4::identity();
	
	std::cout << (matrix3 == matrix4) << std::endl;
	std::cout << (matrix3 == matrix1) << std::endl;
	std::cout << (matrix3 != matrix4) << std::endl;

	math::mat4 matrix5 = math::mat4::orthographic(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	math::mat4 matrix6 = math::mat4::perspective(math::degrees(45.0f), 0.45f, 1.0f, 2.0f);
	math::mat4 matrix7 = math::mat4::translation(math::vec3(1.0f, 1.0f, 1.0f));
	math::mat4 matrix8 = math::mat4::rotation(math::degrees(45.0f), math::vec3(1.0f, 1.0f, 1.0f));
	math::mat4 matrix9 = math::mat4::scale(math::vec3(1.0f, 1.0f, 1.0f));

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