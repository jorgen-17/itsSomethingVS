#pragma once

#include <string>
#include "window.h"

namespace itsSomething
{
	namespace graphics
	{
		window::window(std::string name, int width, int height)
		{
			this->name = name;
			this->width = width;
			this->height = height;
		}

	}
}
