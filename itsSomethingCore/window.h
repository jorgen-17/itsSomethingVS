#pragma once

#include <string>
#include <glfw3.h>

namespace itsSomething
{
	namespace graphics
	{
		class window
		{
		private:
			//members
			std::string title;
			int width, height;
			GLFWwindow *pWindow;
			//functions
			bool init();
		public:
			window(std::string name, int width, int height);
			~window();
			void clear() const;
			void update();
			bool closed() const;
			inline int getWidth() { return this->width; };
			inline int getHeight() { return this->height; };
		};
	}
}