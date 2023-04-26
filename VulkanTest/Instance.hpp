#pragma once
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include "Window.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

class VulkanInstance {
public:
	VulkanInstance(Window* window, std::vector<const char*>& validationLayers);
	VulkanInstance() {};
	VkInstance instance;

private:
	Window* window;
	bool checkValidationLayerSupport(std::vector<const char*>& _validationLayers);
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
		std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

		return VK_FALSE;
	}
};