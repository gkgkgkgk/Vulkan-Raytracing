#include "Semaphore.hpp"

Semaphore::Semaphore(Device* _device) {
    VkSemaphoreCreateInfo semaphoreInfo{};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    if (vkCreateSemaphore(_device->device, &semaphoreInfo, nullptr, &imageAvailableSemaphore) != VK_SUCCESS ||
        vkCreateSemaphore(_device->device, &semaphoreInfo, nullptr, &renderFinishedSemaphore) != VK_SUCCESS){
        throw std::runtime_error("failed to create semaphores!");
    }

    std::cout << "Created Semaphore." << std::endl;
}