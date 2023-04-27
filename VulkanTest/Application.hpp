#include "Window.hpp"
#include "Instance.hpp"
#include "DebugMessenger.hpp"
#include "Surface.hpp"
#include "Device.hpp"
#include "ValidationLayers.hpp"
#include "SwapChain.hpp"
#include "ImageView.hpp"
#include "GraphicsPipeline.hpp"
#include "RenderPass.hpp"
#include "FrameBuffer.hpp"
#include "CommandPool.hpp"
#include "CommandBuffer.hpp"
#include "Semaphore.hpp"
#include "Fence.hpp"

class RayTracingApplication {
private:
    Window window;
    VulkanInstance instance;
    DebugMessenger debugMessenger;
    Surface surface;
    Device device;
    SwapChain swapChain;
    ImageView imageView;
    RenderPass renderPass;
    GraphicsPipeline pipeline;
    FrameBuffer frameBuffer;
    CommandPool commandPool;
    CommandBuffer commandBuffer;
    Semaphore semaphore;
    Fence fence;

    void loop();
    void render(const uint32_t imageIndex);
    void drawFrame();

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
        std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

        return VK_FALSE;
    }

public:
    RayTracingApplication() {};
    void run();

};