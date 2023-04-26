#pragma once
#include <GLFW/glfw3.h>
#include <vector>

class Window {
public:
	Window() {};
	Window(int height, int width);
	std::vector<const char*> GetRequiredExtensions();

	int height;
	int width;
	GLFWwindow* glfwWindow;
};