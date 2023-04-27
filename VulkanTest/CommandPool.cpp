/* In vulkan, commands like drawing and memory transfers are not directly executed.
* Instead, commands are recorded and stored in a buffer, and then each command is executed from the buffer.
* To make a Command Buffer, we first need a command pool. Command pools manage the memory used to store command buffers.
*/

#include "CommandPool.hpp"

CommandPool::CommandPool(Device* _device, Surface* _surface) {
	QueueFamilyIndices queueFamilyIndices = findQueueFamilies(_device->physicalDevice, _surface->surface);

	VkCommandPoolCreateInfo poolInfo{};
	poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	poolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
	poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily.value();

	if (vkCreateCommandPool(_device->device, &poolInfo, nullptr, &commandPool) != VK_SUCCESS) {
		throw std::runtime_error("failed to create command pool!");
	}

	std::cout << "Command pool created!" << std::endl;
}