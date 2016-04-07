#pragma once

#include <string>
#include <glew.h>
#include <glfw3.h>

namespace itsSomething
{
	namespace graphics
	{
#define MAX_KEYS	1024
#define MAX_BUTTONS 32

		class window
		{
		private:
			//members
			std::string title;
			int width, height;
			bool keys[MAX_KEYS];
			bool mouseButtons[MAX_BUTTONS];
			double mouseX, mouseY;
			GLFWwindow *pWindow;
			//functions
			bool init();
			friend static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouseButtonCallback(GLFWwindow* win, int button, int action, int mods);
			friend static void mousePositionCallback(GLFWwindow* win, double xpos, double ypos);
		public:
			window(std::string name, int width, int height);
			~window();
			void clear() const;
			void update();
			bool closed() const;
			inline int getWidth() { return this->width; };
			inline int getHeight() { return this->height; };
			bool isKeyPressed(unsigned int keyCode);
			bool isMouseButtonPressed(unsigned int mouseButtonCode);
			inline double getMouseX() { return this->mouseX; };
			inline double getMouseY() { return this->mouseY; };
		};
	}
}