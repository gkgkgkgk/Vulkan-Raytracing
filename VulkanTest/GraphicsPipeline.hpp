#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "vulkan/vulkan.h"
#include "Shader.hpp"
#include "Device.hpp"

class GraphicsPipeline {
public:
	GraphicsPipeline() {};
	GraphicsPipeline(Device* _device);
private:
	VkPipelineLayout pipelineLayout;
};