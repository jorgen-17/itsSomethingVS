#include <string>
#include "window.h"
#include <iostream>
#include <cassert>

namespace itsSomething
{
	namespace graphics
	{
		void resize(GLFWwindow* win, int width, int height);
		void keyCallback(GLFWwindow* win, int key, int scancode, int action, int mods);
		void mouseButtonCallback(GLFWwindow* win, int button, int action, int mods);
		void mousePositionCallback(GLFWwindow* win, double xpos, double ypos);

		window::window(std::string title, int width, int height)
		{
			this->title = title;
			this->width = width;
			this->height = height;

			if(!this->init())
				glfwTerminate();
			
			for (int i = 0; i < MAX_KEYS; i++)
			{
				this->keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				this->mouseButtons[i] = false;
			}
		}

		window::~window()
		{
			glfwTerminate();
		}

		void window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(this->pWindow);
		}

		void window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool window::init()
		{
			if (!glfwInit())
			{
				std::cout << "could not initialize glfw" << std::endl;
				return false;
			}

			this->pWindow = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);
			
			if(!this->pWindow)
			{
				std::cout << "Failed to create window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(this->pWindow);
			glfwSetWindowUserPointer(this->pWindow, this);
			glfwSetWindowSizeCallback(this->pWindow, resize);
			glfwSetKeyCallback(this->pWindow, keyCallback);
			glfwSetMouseButtonCallback(this->pWindow, mouseButtonCallback);
			glfwSetCursorPosCallback(this->pWindow, mousePositionCallback);

			if(glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize glew" << std::endl;
			}



			return true;
		}

		bool window::closed() const
		{
			return glfwWindowShouldClose(this->pWindow) == 1;
		}

		bool window::isKeyPressed(unsigned int keyCode) const
		{
			assert(keyCode < MAX_KEYS && keyCode >= 0);

			return this->keys[keyCode];
		}

		bool window::isMouseButtonPressed(unsigned int mouseButtonCode) const
		{
			assert(mouseButtonCode < MAX_BUTTONS && mouseButtonCode >= 0);

			return this->mouseButtons[mouseButtonCode];
		}

		void resize(GLFWwindow* win, int width, int height)
		{
			window* userWindow = (window*)glfwGetWindowUserPointer(win);
			glViewport(0, 0, width, height);
		}

		void keyCallback(GLFWwindow* win, int key, int scancode, int action, int mods)
		{
			window* userWindow = (window*)glfwGetWindowUserPointer(win);
			userWindow->keys[key] = action != GLFW_RELEASE;
		}

		void mouseButtonCallback(GLFWwindow* win, int button, int action, int mods)
		{
			window* userWindow = (window*)glfwGetWindowUserPointer(win);
			userWindow->mouseButtons[button] = action != GLFW_RELEASE;
		}

		void mousePositionCallback(GLFWwindow* win, double xpos, double ypos)
		{
			window* userWindow = (window*)glfwGetWindowUserPointer(win);
			userWindow->mouseX = xpos;
			userWindow->mouseY = ypos;
		}
	}             
}                                                                                                                                                                                                                                                                                                                         