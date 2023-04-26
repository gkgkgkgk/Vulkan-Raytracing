#include "Surface.hpp"

Surface::Surface(VulkanInstance* _instance, Window* _window) {
    if (glfwCreateWindowSurface(_instance->instance, _window->glfwWindow, nullptr, &surface) != VK_SUCCESS) {
        throw std::runtime_error("failed to create window surface!");
    }
    std::cout << "Created Surface!" << std::endl;
}