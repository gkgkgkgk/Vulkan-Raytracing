#pragma once

#include "vulkan/vulkan.h"
#include <vector>
#include "SwapChain.hpp"
#include "Device.hpp"

class ImageView {
public:
	ImageView() {};
	ImageView(Device* _device, SwapChain* _swapChain);
	std::vector<VkImageView> swapChainImageViews;
};