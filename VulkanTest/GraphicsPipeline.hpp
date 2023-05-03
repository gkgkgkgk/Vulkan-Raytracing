#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "vulkan/vulkan.h"
#include "Shader.hpp"
#include "Device.hpp"
#include "RenderPass.hpp"
#include "Vertex.hpp"
#include "DescriptorSetlayout.hpp"

class GraphicsPipeline {
public:
	GraphicsPipeline() {};
	GraphicsPipeline(Device* _device, RenderPass* _renderPass, DescriptorSetLayout* _descriptorSetLayout);
	VkPipeline graphicsPipeline;
	VkPipelineLayout pipelineLayout;
};