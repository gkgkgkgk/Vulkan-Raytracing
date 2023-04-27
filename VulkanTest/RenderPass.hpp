#include "Device.hpp"
#include "SwapChain.hpp"
class RenderPass {
public:
	RenderPass() {};
	RenderPass(Device * _device, SwapChain* _swapChain);
	VkRenderPass renderPass;
};