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
    pipeline = GraphicsPipeline(&device, &renderPass);
    frameBuffer = FrameBuffer(&device, &imageView, &renderPass, &swapChain);
    commandPool = CommandPool(&device, &surface);
    commandBuffer = CommandBuffer(&commandPool, &device);
    semaphore = Semaphore(&device);
    fence = Fence(&device);

    //render();
    loop();
}

void RayTracingApplication::render(const uint32_t imageIndex) {
    VkRenderPassBeginInfo renderPassInfo{};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassInfo.renderPass = renderPass.renderPass;
    renderPassInfo.framebuffer = frameBuffer.swapChainFramebuffers[imageIndex];
    renderPassInfo.renderArea.offset = { 0, 0 };
    renderPassInfo.renderArea.extent = swapChain.swapChainExtent;

    VkClearValue clearColor = { {{0.0f, 0.0f, 0.0f, 1.0f}} };
    renderPassInfo.clearValueCount = 1;
    renderPassInfo.pClearValues = &clearColor;

    vkCmdBeginRenderPass(commandBuffer.commandBuffer, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

    vkCmdBindPipeline(commandBuffer.commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline.graphicsPipeline);

    VkViewport viewport{};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = (float)swapChain.swapChainExtent.width;
    viewport.height = (float)swapChain.swapChainExtent.height;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;
    vkCmdSetViewport(commandBuffer.commandBuffer, 0, 1, &viewport);

    VkRect2D scissor{};
    scissor.offset = { 0, 0 };
    scissor.extent = swapChain.swapChainExtent;
    vkCmdSetScissor(commandBuffer.commandBuffer, 0, 1, &scissor);

    vkCmdDraw(commandBuffer.commandBuffer, 3, 1, 0, 0);

    vkCmdEndRenderPass(commandBuffer.commandBuffer);
}

void RayTracingApplication::drawFrame() {

}

void RayTracingApplication::loop() {
    while (!glfwWindowShouldClose(window.glfwWindow)) {
        glfwPollEvents();
        drawFrame();
    }
}

namespace MyNamespace {
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
        std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

        return VK_FALSE;
    }
}