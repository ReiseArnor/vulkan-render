set(CPP_SOURCE main.cpp)

if(MSVC)
    set(CPP_FLAGS /W4 /permissive-)
else()
    set(CPP_FLAGS -Wall -Wextra -Wconversion -Wpedantic)
    set(CPP_LINKING_OPTS -fno-omit-frame-pointer -fsanitize=undefined,address)
endif()

Include(FetchContent)
message(STATUS "Fetching glfw...")
FetchContent_Declare(
  glfm
  GIT_REPOSITORY git@github.com:glfw/glfw.git
  GIT_TAG        3.4 # or a later release
)
FetchContent_MakeAvailable(glfm)

message(STATUS "Fetching glm...")
FetchContent_Declare(
  glm
  GIT_REPOSITORY git@github.com:g-truc/glm.git
  GIT_TAG       1.0.1
)
FetchContent_MakeAvailable(glm)

add_executable(${PROJECT_NAME} ${CPP_SOURCE})
target_compile_options(${PROJECT_NAME} PRIVATE ${CPP_FLAGS})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan glm glfw)
target_link_options(${PROJECT_NAME} PRIVATE ${CPP_LINKING_OPTS})
