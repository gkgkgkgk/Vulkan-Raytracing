/*
	To use the VkImages that are stored in the swap chain, we need a VkImageView object. 
	Literally speaking, this is used to view an image. It describes how to access images,
	inlcuding different types of images like depth textures.
*/

#include "ImageView.hpp"

ImageView::ImageView(Device *_device, SwapChain* _swapChain) {
	// Make a view for each image in the swap chain
	swapChainImageViews.resize(_swapChain->swapChainImages.size());

	// For each image in the swap chain, configure the view
	for (size_t i = 0; i < _swapChain->swapChainImages.size(); i++) {
		VkImageViewCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		createInfo.image = _swapChain->swapChainImages[i];
		createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
		createInfo.format = _swapChain->swapChainImageFormat;

		// default mappings for color mixing
		createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;

		// this dictates how to access the image. We only need one layer because we are rendering a 2D image (as opposed to VR or stereographic images)
		createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		createInfo.subresourceRange.baseMipLevel = 0;
		createInfo.subresourceRange.levelCount = 1;
		createInfo.subresourceRange.baseArrayLayer = 0;
		createInfo.subresourceRange.layerCount = 1;
		if (vkCreateImageView(_device->device, &createInfo, nullptr, &swapChainImageViews[i]) != VK_SUCCESS) {
			throw std::runtime_error("failed to create image views!");
		}
	}

	std::cout << "Made an image view for  " << _swapChain->swapChainImages.size() << " images on the swap chain!" << std::endl;
}