#include "Semaphore.hpp"

Semaphore::Semaphore(Device* _device, int max_frames_in_flight) {
    imageAvailableSemaphores.resize(max_frames_in_flight);
    renderFinishedSemaphores.resize(max_frames_in_flight);
    VkSemaphoreCreateInfo semaphoreInfo{};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    for (size_t i = 0; i < max_frames_in_flight; i++) {
        if (vkCreateSemaphore(_device->device, &semaphoreInfo, nullptr, &imageAvailableSemaphores[i]) != VK_SUCCESS ||
            vkCreateSemaphore(_device->device, &semaphoreInfo, nullptr, &renderFinishedSemaphores[i]) != VK_SUCCESS){

            throw std::runtime_error("failed to create synchronization objects for a frame!");
        }
    }

    std::cout << "Created Semaphores." << std::endl;
}