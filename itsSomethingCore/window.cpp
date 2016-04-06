#include <string>
#include "window.h"
#include <iostream>

namespace itsSomething
{
	namespace graphics
	{
		void resize(GLFWwindow* win, int width, int height);

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

			if(glewInit() != GLEW_OK)
			{
				std::cout << "COuld not initialize glew" << std::endl;
			}



			return true;
		}

		bool window::closed() const
		{
			return glfwWindowShouldClose(this->pWindow);
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

	}             
}                                                                                                                                                                                                                                                                                                                         