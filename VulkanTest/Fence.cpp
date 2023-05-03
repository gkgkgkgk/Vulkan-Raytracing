#include "Fence.hpp"

Fence::Fence(Device* _device, int max_frames_in_flight) {
    inFlightFences.resize(max_frames_in_flight);
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    for (size_t i = 0; i < max_frames_in_flight; i++) {
        if (vkCreateFence(_device->device, &fenceInfo, nullptr, &inFlightFences[i]) != VK_SUCCESS) {
            throw std::runtime_error("failed to create fence!");
        }
    }

    std::cout << "Created Fence." << std::endl;
}