#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "core/event.hpp"
#include <graphics/graphics.h>
#include <iostream>

float screenAspectRatio = 0;
Event<int, int> ScreenSizeChange;

void SetAspectRatio(int width, int height)
{
    screenAspectRatio = (float)width / (float)height;
}

void Framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);

    SetAspectRatio(width, height);
    std::cout << "Starting an Invoke" << std::endl;
    ScreenSizeChange.Invoke(width, height);
    ScreenSizeChange.Test();
}

GLFWwindow* CreateWindow(int screen_width, int screen_height, const char* title)
{
    SetAspectRatio(screen_width, screen_height);

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(screen_width, screen_height, title, NULL, NULL);

    if (window == NULL) 
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, Framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1); 
    }

    return window;
}
