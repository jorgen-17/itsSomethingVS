                               
#pragma once

#include <string>
#include "window.h"
#include <iostream>

namespace itsSomething
{
	namespace graphics
	{
		window::window(std::string title, int width, int height)
		{
			this->title = title;
			this->width = width;
			this->height = height;

			if(!this->init())
			{
				glfwTerminate();
			}
		}

		window::~window()
		{
			glfwTerminate();
		}

		void window::update() const
		{
			glfwPollEvents();
			glfwSwapBuffers(this->pWindow);
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
			return true;
		}

		bool window::closed() const
		{
			return glfwWindowShouldClose(this->pWindow);
		}

	}
                  
}                                                                                                                                                                                                                                                                                                                         