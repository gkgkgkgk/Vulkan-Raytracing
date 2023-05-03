#include "CommandBuffer.hpp"

CommandBuffer::CommandBuffer(CommandPool* _commandPool, Device* _device, int max_frames_in_flight) {
    commandBuffers.resize(max_frames_in_flight);

    VkCommandBufferAllocateInfo allocInfo{};
    allocInfo.commandBufferCount = (uint32_t)commandBuffers.size();
	allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	allocInfo.commandPool = _commandPool->commandPool;
	allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	allocInfo.commandBufferCount = (uint32_t) commandBuffers.size();

	if (vkAllocateCommandBuffers(_device->device, &allocInfo, commandBuffers.data()) != VK_SUCCESS) {
		throw std::runtime_error("failed to allocate command buffers!");
	}
}

void CommandBuffer::recordCommandBuffer(RenderPass &renderPass, FrameBuffer &frameBuffer, SwapChain &swapChain, GraphicsPipeline &pipeline, uint32_t imageIndex, int currentFrame) {
	VkCommandBufferBeginInfo beginInfo{};
	beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

	if (vkBeginCommandBuffer(commandBuffers[currentFrame], &beginInfo) != VK_SUCCESS) {
		throw std::runtime_error("failed to begin recording command buffer!");
	}

    VkRenderPassBeginInfo renderPassInfo{};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassInfo.renderPass = renderPass.renderPass;
    renderPassInfo.framebuffer = frameBuffer.swapChainFramebuffers[imageIndex];
    renderPassInfo.renderArea.offset = { 0, 0 };
    renderPassInfo.renderArea.extent = swapChain.swapChainExtent;

    VkClearValue clearColor = { {{0.0f, 0.0f, 0.0f, 1.0f}} };
    renderPassInfo.clearValueCount = 1;
    renderPassInfo.pClearValues = &clearColor;

    vkCmdBeginRenderPass(commandBuffers[currentFrame], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

    vkCmdBindPipeline(commandBuffers[currentFrame], VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline.graphicsPipeline);

    VkViewport viewport{};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = (float)swapChain.swapChainExtent.width;
    viewport.height = (float)swapChain.swapChainExtent.height;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;
    vkCmdSetViewport(commandBuffers[currentFrame], 0, 1, &viewport);

    VkRect2D scissor{};
    scissor.offset = { 0, 0 };
    scissor.extent = swapChain.swapChainExtent;
    vkCmdSetScissor(commandBuffers[currentFrame], 0, 1, &scissor);

    vkCmdDraw(commandBuffers[currentFrame], 3, 1, 0, 0);

    vkCmdEndRenderPass(commandBuffers[currentFrame]);

    if (vkEndCommandBuffer(commandBuffers[currentFrame]) != VK_SUCCESS) {
        throw std::runtime_error("failed to record command buffer!");
    }
}