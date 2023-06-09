#include "Shader.hpp"

Shader::Shader(const std::string& filename, Device* _device) {
    auto shaderCode = readFile(filename);
    shaderModule = createShaderModule(shaderCode, _device->device);

    std::cout << "Loaded shader: " << filename << std::endl;
}


std::vector<char> Shader::readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("failed to open file!");
    }

    size_t fileSize = (size_t)file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();

    return buffer;
}

VkShaderModule Shader::createShaderModule(const std::vector<char>& code, VkDevice device) {
    VkShaderModuleCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = code.size();
    createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

    VkShaderModule shaderModule;
    if (vkCreateShaderModule(device, &createInfo, nullptr, &shaderModule) != VK_SUCCESS) {
        throw std::runtime_error("failed to create shader module!");
    }


    return shaderModule;
}

VkPipelineShaderStageCreateInfo Shader::createShaderStage(VkShaderStageFlagBits stage) {
    VkPipelineShaderStageCreateInfo vertShaderStageInfo{};
    vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    vertShaderStageInfo.stage = stage;
    vertShaderStageInfo.module = shaderModule;
    vertShaderStageInfo.pName = "main";

    return vertShaderStageInfo;
}