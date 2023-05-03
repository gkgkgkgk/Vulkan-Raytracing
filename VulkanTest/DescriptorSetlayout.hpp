#pragma once
#include "Device.hpp"

class DescriptorSetLayout{
public:
	DescriptorSetLayout() {};
	DescriptorSetLayout(Device *device);
	VkDescriptorSetLayout descriptorSetLayout;
};