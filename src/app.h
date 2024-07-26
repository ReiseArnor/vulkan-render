#include "GLFW/glfw3.h"
#include <array>
#include <optional>
#include <vulkan/vulkan_core.h>

struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;
  bool isComplete() { return graphicsFamily.has_value(); }
};

class VulkanApp {
public:
  void run();

private:
  void initVulkan();
  void mainLoop();
  void cleanup();
  void initWindow();
  void createInstance();
  bool checkValidationLayerSupport();
  void pickPhysicalDevice();
  bool isDeviceSuitable(VkPhysicalDevice device);
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

private:
  GLFWwindow *window;
  const uint32_t WIDTH = 800;
  const uint32_t HEIGHT = 600;
  VkInstance instance;
  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  const std::array<const char *, 1> validationLayers = {
      "VK_LAYER_KHRONOS_validation"};

#ifdef NDEBUG
  const bool enableValidationLayers = false;
#else
  const bool enableValidationLayers = true;
#endif
};
