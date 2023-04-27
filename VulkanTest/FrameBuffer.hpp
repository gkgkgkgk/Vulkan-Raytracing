#include <vector>
#include "vulkan/vulkan.h"
#include "ImageView.hpp"
#include "RenderPass.hpp"
#include "Device.hpp"
#include "SwapChain.hpp"

class FrameBuffer {
public:
	FrameBuffer() {};
	FrameBuffer(Device* _device, ImageView* _imageView, RenderPass* _renderPass, SwapChain* _swapChain);
	std::vector<VkFramebuffer> swapChainFramebuffers;
};