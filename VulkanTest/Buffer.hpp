#pragma once
#include "vulkan/vulkan.hpp"
#include "Device.hpp"
#include "Vertex.hpp"
#include "CommandPool.hpp"

class Buffer {
public:
	Buffer() {};
	Buffer(Device* _device);
	VkBuffer buffer;
	VkDeviceMemory bufferMemory;
	uint32_t size;
	void createVertexBuffer(std::vector<Vertex> vertices, CommandPool* commandPool);
	void createIndexBuffer(std::vector<uint16_t> indices, CommandPool* commandPool);
	void createUniformBuffer(size_t size, std::vector<VkBuffer> uniformBuffers, std::vector<VkDeviceMemory> uniformBuffersMemory, std::vector<void*> uniformBuffersMapped, CommandPool* commandPool, int max_frames_in_flight);

	void copyFromBuffer(CommandPool* commandPool, VkBuffer srcBuffer, VkDeviceSize size);

private:
	uint32_t findMemoryType(VkPhysicalDevice physicalDevice, uint32_t typeFilter, VkMemoryPropertyFlags properties);
	void createBuffer(VkDeviceSize size, const VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
	Device* device;
};