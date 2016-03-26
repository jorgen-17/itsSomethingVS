#include <glfw3.h>
#include <iostream>

int main()
{
	if (!glfwInit())
		std::cout << "Error" << std::endl;
	else 
		std::cout << "success" << std::endl;

	
	system("PAUSE");
	return 0;
}	