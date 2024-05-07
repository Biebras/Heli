#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <core/event_manager.h>
#include <graphics/graphics.h>
#include <graphics/shapes.h>
#include <graphics/resources.h>

#include <iostream>

float ScreenAspectRatio = 0;

void SetAscpectRatio(int width, int height)
{
    float aspect = (float)width / (float)height;

    if (aspect < 1)
        aspect = (float)height / (float)width;

    ScreenAspectRatio = aspect;
    windowEvents.OnAspectRatioChange.Invoke(ScreenAspectRatio);
}

void Framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    SetAscpectRatio(width, height);

    glViewport(0, 0, width, height);

    windowEvents.OnSizeChange.Invoke(width, height);
}

GLFWwindow* CreateWindow(int screen_width, int screen_height, const char* title)
{
    SetAscpectRatio(screen_width, screen_height);

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
    { std::cout << "Failed to initialize GLAD" << std::endl; exit(-1); }

    //Other Init
    LoadHeliResources(); 
    InitShapes();

    return window;
}
