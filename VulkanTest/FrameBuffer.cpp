// For every imageview we have, we need a frame buffer.

#include "FrameBuffer.hpp"

FrameBuffer::FrameBuffer(Device* _device, ImageView* _imageView, RenderPass* _renderPass, SwapChain* _swapChain) {
	swapChainFramebuffers.resize(_imageView->swapChainImageViews.size());

    for (size_t i = 0; i < _imageView->swapChainImageViews.size(); i++) {
        VkImageView attachments[] = {
            _imageView->swapChainImageViews[i]
        };

        VkFramebufferCreateInfo framebufferInfo{};
        framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebufferInfo.renderPass = _renderPass->renderPass;
        framebufferInfo.attachmentCount = 1;
        framebufferInfo.pAttachments = attachments;
        framebufferInfo.width = _swapChain->swapChainExtent.width;
        framebufferInfo.height = _swapChain->swapChainExtent.height;
        framebufferInfo.layers = 1;

        if (vkCreateFramebuffer(_device->device, &framebufferInfo, nullptr, &swapChainFramebuffers[i]) != VK_SUCCESS) {
            throw std::runtime_error("failed to create framebuffer!");
        }
    }

    std::cout << "Initalized frame buffers." << std::endl;
}