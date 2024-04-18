#include <graphics/camera.hpp>
#include <graphics/graphics.h>
#include <iostream>

void OnScreenSizeChange(int width, int height)
{
    std::cout << "Received" << std::endl;
    std::cout << width << " || " << height << std::endl;
}

Camera::Camera()
{
    _zoomLevel = 12;
   ScreenSizeChange.Subscribe(OnScreenSizeChange); 
}

Camera::Camera(float zoomLevel)
{
    _zoomLevel = zoomLevel;
}

glm::mat4 Camera::GetVP()
{
    glm::mat4 view = glm::mat4(1);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    return _projection * view;
}

void Camera::UpdateCamera(float aspectRatio)
{
    _projection  = glm::ortho(-aspectRatio * _zoomLevel, 
                               aspectRatio * _zoomLevel, 
                              -_zoomLevel, _zoomLevel, -100.0f, 100.0f);
}

void Camera::SetZoomLevel(float zoomLevel)
{
    _zoomLevel = zoomLevel;
}

