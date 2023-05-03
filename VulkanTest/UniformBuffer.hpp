#pragma once
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <chrono>
#include <glm/glm.hpp>
#include "Buffer.hpp"
#include "CommandPool.hpp"
#include "SwapChain.hpp"

class UniformBuffer {
public:
    UniformBuffer() {};
    UniformBuffer(Device* _device, CommandPool* _commandPool, int max_frames_in_flight);

    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;

    void update(SwapChain* swapChain, uint32_t currentImage);
    void createBuffer(Device* device, VkDeviceSize size, const VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
    uint32_t findMemoryType(VkPhysicalDevice physicalDevice, uint32_t typeFilter, VkMemoryPropertyFlags properties);

    struct UniformBufferObject {
        alignas(16) glm::mat4 model;
        alignas(16) glm::mat4 view;
        alignas(16) glm::mat4 proj;
    };

    size_t uboSize;

private:
    Buffer buffer;
};
