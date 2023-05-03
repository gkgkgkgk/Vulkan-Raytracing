#include "vulkan/vulkan.h"
#include <iostream>
#include "Device.hpp"

class Semaphore {
public:
	Semaphore() {};
	Semaphore(Device* _device, int max_frames_in_flight);
	std::vector<VkSemaphore> imageAvailableSemaphores;
	std::vector<VkSemaphore> renderFinishedSemaphores;
};