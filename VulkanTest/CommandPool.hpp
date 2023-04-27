#pragma once

#include "vulkan/vulkan.h"
#include "QueueFamilyIndices.hpp"
#include "Device.hpp"
#include "Surface.hpp"

class CommandPool {
public:
	CommandPool() {};
	CommandPool(Device* _device, Surface* _surface);
	VkCommandPool commandPool;
};