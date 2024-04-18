#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <core/event.hpp>

extern float screenAspectRatio;
extern Event<int, int> ScreenSizeChange;

void Framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* CreateWindow(int screen_width, int screen_height, const char* title);

#endif
