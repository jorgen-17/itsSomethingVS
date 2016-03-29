#include <glfw3.h>
#include <iostream>
#include "window.h"

int main()
{
	using namespace itsSomething;

	graphics::window win("itsSomething!", 800, 600);

	while(!win.closed())
	{
		win.update();
	}

	return 0;
}	