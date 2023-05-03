#include "Device.hpp"
#include "CommandPool.hpp"
#include "RenderPass.hpp"
#include "FrameBuffer.hpp"
#include "SwapChain.hpp"
#include "GraphicsPipeline.hpp"
class CommandBuffer {
public:
	CommandBuffer() {};
	CommandBuffer(CommandPool* _commandPool, Device* _device, int max_frames_in_flight);
	std::vector<VkCommandBuffer> commandBuffers;
	void recordCommandBuffer(RenderPass &renderPass, FrameBuffer &frameBuffer, SwapChain &swapChain, GraphicsPipeline &pipeline, uint32_t imageIndex, int currentFrame);
};