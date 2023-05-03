#include "vulkan/vulkan.h"
#include "Device.hpp"
#include <iostream>

class Fence {
public:
	Fence() {};
	Fence(Device* _device, int max_frames_in_flight);
	std::vector<VkFence> inFlightFences;
private:
	VkFenceCreateInfo fenceInfo{};
};