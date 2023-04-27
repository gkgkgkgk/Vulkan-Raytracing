#include "vulkan/vulkan.h"
#include <iostream>
#include "Device.hpp"

class Semaphore {
public:
	Semaphore() {};
	Semaphore(Device* _device);
	VkSemaphore imageAvailableSemaphore;
	VkSemaphore renderFinishedSemaphore;
};