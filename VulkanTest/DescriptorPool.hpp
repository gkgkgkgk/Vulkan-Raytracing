#pragma once
#include "vulkan/vulkan.hpp"
#include "Device.hpp"
#include "DescriptorSetLayout.hpp"
#include "UniformBuffer.hpp"
class DescriptorPool {
public:
	DescriptorPool() {};
	DescriptorPool(Device* _device, DescriptorSetLayout*_descriptorSetLayout, UniformBuffer *_uniformBuffer, int max_frames_in_flight);

	VkDescriptorPool descriptorPool;
	std::vector<VkDescriptorSet> descriptorSets;
};