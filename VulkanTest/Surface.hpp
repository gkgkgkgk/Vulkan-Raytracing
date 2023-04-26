#pragma once
#include <vulkan/vulkan.h>
#include "Instance.hpp"

class Surface {
public:
	Surface() {};
	Surface(VulkanInstance* _instance, Window* window);
	VkSurfaceKHR surface;
};