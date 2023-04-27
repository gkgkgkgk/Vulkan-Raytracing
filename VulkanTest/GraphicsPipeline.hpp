/* The graphics pipeline has many steps. The basic steps are:
* - Input Assembler: This collects raw vertex data from buffers. Basically, this is similar to a VAO or EBO in OpenGL.
* - Vertex Shader: Renders every vertex by converting from world space to screen space.
* - Tesselation Shaders: Subdivides geometry to allow for transformations.
* - Geometry Shaders: Runs for every triangle in the scene, and can modify the geometry on the fly.
* - Rasterization: Every Triangle is assigned a fragment, and all of the fragments that appear on the screen and first on the depth buffer are colored in.
* - Fragment Shader: For every fragment, this can do some sort of operation such as lighting or texturing.
* - Color Blending: Colors are blended between fragments that share pixels (think of a tinted blue window in front of a red square) aka glBlendFunc
* 
* This pipeline will be created and modified for Raytracing. Instead of using the traditional vertex shaders and fragment shaders,
* we'll have a shader that creates an image by cycling through every pixal and shooting off rays to collect color data.
*/

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
};