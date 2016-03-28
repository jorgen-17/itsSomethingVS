                               
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

			this->init();
		}

		window::~window()
		{
		}

		void window::update() const
		{
		}

		void window::init()
		{
			this->pWindow = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);
			
			if(!this->pWindow)
			{
				std::cout << "Failed to create window" << std::endl;
				return;
			}
		}
	}
                  
}                                                                                                                                                                                                                                                                                                                         