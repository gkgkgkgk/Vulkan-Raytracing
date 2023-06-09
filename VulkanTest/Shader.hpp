#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "vulkan/vulkan.h"
#include "Device.hpp"

class Shader {
public:
	Shader() {};
	Shader(const std::string& filename, Device* _device);
	VkPipelineShaderStageCreateInfo createShaderStage(VkShaderStageFlagBits stage);
	VkShaderModule shaderModule;

private:
	std::vector<char> readFile(const std::string& filename);
	VkShaderModule createShaderModule(const std::vector<char>& code, VkDevice device);
	VkPipelineShaderStageCreateInfo shaderStageInfo{};
};