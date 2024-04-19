#include "core/event.hpp"
#include <graphics/camera.hpp>
#include <graphics/graphics.h>

Camera::Camera()
{
    _zoomLevel = 12;
    UpdateProjection(ScreenAspectRatio); 
    _onScreenUpdateEventId = ScreenSizeChangeEvent.Subscribe(MethodSubscriber(OnScreenSizeUpdate)); 
}

Camera::Camera(float zoomLevel)
{
    _zoomLevel = zoomLevel;
    UpdateProjection(ScreenAspectRatio); 
    _onScreenUpdateEventId = ScreenSizeChangeEvent.Subscribe(MethodSubscriber(OnScreenSizeUpdate)); 
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

void Camera::UpdateProjection(int aspectRatio)
{
    _projection  = glm::ortho(-aspectRatio * _zoomLevel, 
                               aspectRatio * _zoomLevel, 
                              -_zoomLevel, _zoomLevel, -100.0f, 100.0f);
}

void Camera::OnScreenSizeUpdate(int width, int height)
{
    float aspect = (float)width / (float)height;
    UpdateProjection(aspect);
}

void Camera::SetZoomLevel(float zoomLevel)
{
    _zoomLevel = zoomLevel;
}

