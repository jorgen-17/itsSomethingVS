#pragma once

#include <string>

namespace itsSomething
{
	namespace graphics
	{
		class window
		{
		private:
			std::string name;
			int width, height;

		public:
			window(std::string name, int width, int height);
			~window();
			void update() const;
		};
	}
}