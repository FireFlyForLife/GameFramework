#pragma once
#include <string>

struct GLFWwindow;

namespace Screen {
	extern GLFWwindow* window;
	extern int width;
	extern int height;
	extern std::string title;
}
