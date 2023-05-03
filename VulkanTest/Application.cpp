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
    commandBuffer = CommandBuffer(&commandPool, &device, max_frames_in_flight);
    semaphore = Semaphore(&device, max_frames_in_flight);
    fence = Fence(&device, max_frames_in_flight);

    loop();
}


void RayTracingApplication::drawFrame() {
    vkWaitForFences(device.device, 1, &fence.inFlightFences[currentFrame], VK_TRUE, UINT64_MAX);
    vkResetFences(device.device, 1, &fence.inFlightFences[currentFrame]);

    uint32_t imageIndex;
    vkAcquireNextImageKHR(device.device, swapChain.swapChain, UINT64_MAX, semaphore.imageAvailableSemaphores[currentFrame], VK_NULL_HANDLE, &imageIndex);
    
    vkResetCommandBuffer(commandBuffer.commandBuffers[currentFrame], /*VkCommandBufferResetFlagBits*/ 0);
    commandBuffer.recordCommandBuffer(renderPass, frameBuffer, swapChain, pipeline, imageIndex, currentFrame);

    VkSubmitInfo submitInfo{};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore waitSemaphores[] = { semaphore.imageAvailableSemaphores[currentFrame] };
    VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = waitSemaphores;
    submitInfo.pWaitDstStageMask = waitStages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &commandBuffer.commandBuffers[currentFrame];

    VkSemaphore signalSemaphores[] = { semaphore.renderFinishedSemaphores[currentFrame] };
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = signalSemaphores;

    if (vkQueueSubmit(device.graphicsQueue, 1, &submitInfo, fence.inFlightFences[currentFrame]) != VK_SUCCESS) {
        throw std::runtime_error("failed to submit draw command buffer!");
    }

    VkPresentInfoKHR presentInfo{};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = signalSemaphores;

    VkSwapchainKHR swapChains[] = { swapChain.swapChain };
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = swapChains;

    presentInfo.pImageIndices = &imageIndex;

    vkQueuePresentKHR(device.presentQueue, &presentInfo);

    currentFrame = (currentFrame + 1) % max_frames_in_flight;
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