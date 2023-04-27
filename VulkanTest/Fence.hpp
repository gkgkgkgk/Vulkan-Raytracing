#include "vulkan/vulkan.h"
#include "Device.hpp"
#include <iostream>

class Fence {
public:
	Fence() {};
	Fence(Device* _device);
	VkFence inFlightFence;
private:
	VkFenceCreateInfo fenceInfo{};
};