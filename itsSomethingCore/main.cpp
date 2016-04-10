#include "window.h"
#include <iostream>
#include "vec2.h"

int main()
{
	using namespace itsSomething;

	graphics::window win("itsSomething!", 800, 600);
	glClearColor(0.1f, 0.9f, 0.1f, 1.0f);
	std::cout << glGetString(GL_VERSION) << std::endl;

	auto vector1 = math::vec2(1, 1);
	auto vector2 = math::vec2(2, 2);
	auto vector3 = math::vec2(1, 1);

	std::cout << vector1 << std::endl;
	std::cout << (vector1 == vector2) << std::endl;
	std::cout << (vector1 != vector2) << std::endl;
	std::cout << (vector1 == vector3) << std::endl;


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