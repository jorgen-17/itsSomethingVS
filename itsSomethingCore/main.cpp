#include "window.h"
#include <iostream>

int main()
{
	using namespace itsSomething;

	graphics::window win("itsSomething!", 800, 600);
	glClearColor(0.1f, 0.9f, 0.1f, 1.0f);
	std::cout << glGetString(GL_VERSION) << std::endl;

	while(!win.closed())
	{
		win.clear();

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