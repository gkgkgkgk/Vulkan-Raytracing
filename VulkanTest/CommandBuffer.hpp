#include "Device.hpp"
#include "CommandPool.hpp"

class CommandBuffer {
public:
	CommandBuffer() {};
	CommandBuffer(CommandPool* _commandPool, Device* _device);
	VkCommandBuffer commandBuffer;
private:
	void recordCommandBuffer();
};