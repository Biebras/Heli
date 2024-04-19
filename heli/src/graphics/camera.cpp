#include "core/event.hpp"
#include <graphics/camera.hpp>
#include <graphics/graphics.h>
#include <iostream>

void OnScreenSizeChange(int width, int height)
{
    std::cout << "Size Received" << std::endl;
}

Camera::Camera()
{
    _zoomLevel = 12;
}

Camera::Camera(float zoomLevel)
{
    _zoomLevel = zoomLevel;
    _onScreenUpdateEventId = ScreenSizeChangeEvent.Subscribe(MethodSubscriber(UpdateCamera)); 
}

Camera::~Camera()
{
   ScreenSizeChangeEvent.Unsubscribe(_onScreenUpdateEventId); 
}

glm::mat4 Camera::GetVP()
{
    glm::mat4 view = glm::mat4(1);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    return _projection * view;
}

void Camera::UpdateCamera(int width, int height)
{
    printf("Hello?\n");
    float aspectRatio = (float)width / (float)height;

    _projection  = glm::ortho(-aspectRatio * _zoomLevel, 
                               aspectRatio * _zoomLevel, 
                              -_zoomLevel, _zoomLevel, -100.0f, 100.0f);

    ScreenSizeChangeEvent.Unsubscribe(_onScreenUpdateEventId);
}

void Camera::SetZoomLevel(float zoomLevel)
{
    _zoomLevel = zoomLevel;
}

