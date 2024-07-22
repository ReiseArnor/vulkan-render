#include "GLFW/glfw3.h"
#include <vulkan/vulkan_core.h>

class VulkanApp {
public:
  void run();

private:
  void initVulkan();
  void mainLoop();
  void cleanup();
  void initWindow();
  void createInstance();

private:
  GLFWwindow *window;
  const uint32_t WIDTH = 800;
  const uint32_t HEIGHT = 600;
  VkInstance instance;
};
