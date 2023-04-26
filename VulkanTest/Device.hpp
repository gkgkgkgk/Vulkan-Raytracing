#include <vulkan/vulkan.h>
#include "Instance.hpp"
#include "QueueFamilyIndices.hpp"
#include "Surface.hpp"
#include <set>
#include "Extensions.hpp"
#include "ValidationLayers.hpp"

class Device {
public:
	Device() {};
	Device(VulkanInstance* _instance, Surface* surface);
private:
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device;
	VkQueue graphicsQueue;
	VkQueue presentQueue;

	void pickPhysicalDevice(VulkanInstance* _instance);
	bool isDiscreteGPU(VkPhysicalDevice device);
	void createLogicalDevice(Surface* _surface);
};