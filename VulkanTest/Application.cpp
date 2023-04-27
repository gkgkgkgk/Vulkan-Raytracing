#include "Application.hpp"

void RayTracingApplication::run() {
    window = Window(800, 800);
    instance = VulkanInstance(&window, validationLayers);
    debugMessenger = DebugMessenger(&instance);
    surface = Surface(&instance, &window);
    device = Device(&instance, &surface);
    swapChain = SwapChain(&device, &window, &surface);
    imageView = ImageView(&device, &swapChain);
    renderPass = RenderPass(&device, &swapChain);
    pipeline = GraphicsPipeline(&device);

    loop();
}

void RayTracingApplication::loop() {
    while (!glfwWindowShouldClose(window.glfwWindow)) {
        glfwPollEvents();
    }
}

namespace MyNamespace {
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
        std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

        return VK_FALSE;
    }
}