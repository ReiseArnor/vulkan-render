#include "GLFW/glfw3.h"

class VulkanApp {
public:
  void run();

private:
  void initVulkan();
  void mainLoop();
  void cleanup();
  void initWindow();

private:
  GLFWwindow *window;
  const uint32_t WIDTH = 800;
  const uint32_t HEIGHT = 600;
};
