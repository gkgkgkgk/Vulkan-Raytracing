#include "Fence.hpp"

Fence::Fence(Device* _device) {
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    if (vkCreateFence(_device->device, &fenceInfo, nullptr, &inFlightFence) != VK_SUCCESS) {
        throw std::runtime_error("failed to create semaphores!");
    }

    std::cout << "Created Fence." << std::endl;
}