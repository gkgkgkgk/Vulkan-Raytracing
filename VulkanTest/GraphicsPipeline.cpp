#include "GraphicsPipeline.hpp"

GraphicsPipeline::GraphicsPipeline(Device* _device) {
	Shader rayGenShader = Shader("vert.spv", _device);
	Shader fragShader = Shader("frag.spv", _device);
}
