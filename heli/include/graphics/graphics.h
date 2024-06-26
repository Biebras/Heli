#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

extern float ScreenAspectRatio;

void Framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* CreateWindow(int screen_width, int screen_height, const char* title);

#endif
