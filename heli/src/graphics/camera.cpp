#include <core/event.hpp>
#include <core/event_manager.h>
#include <graphics/camera.hpp>
#include <graphics/graphics.h>

Camera::Camera()
{
    _zoomLevel = 12;
    UpdateProjection(ScreenAspectRatio);
    _onScreenAspectUpdateId = windowEvents.OnAspectRatioChange.Subscribe(MethodSubscriber(OnScreenAspectChange));
}

Camera::Camera(float zoomLevel)
{
    _zoomLevel = zoomLevel;
    UpdateProjection(ScreenAspectRatio); 
    _onScreenAspectUpdateId = windowEvents.OnAspectRatioChange.Subscribe(MethodSubscriber(OnScreenAspectChange));
}

Camera::~Camera()
{
    windowEvents.OnAspectRatioChange.Unsubscribe(_onScreenAspectUpdateId);
}

void Camera::ActivateCamera()
{
    cameraEvents.OnActivate.Invoke(this);    
}

glm::mat4 Camera::GetVP()
{
    glm::mat4 view = glm::mat4(1);
    view = glm::translate(view, _cameraPos);

    return _projection * view;
}

void Camera::UpdateProjection(float aspectRatio)
{
    _projection  = glm::ortho(-aspectRatio * _zoomLevel, 
                               aspectRatio * _zoomLevel, 
                              -_zoomLevel, _zoomLevel, -100.0f, 100.0f);
}

void Camera::SetCameraPos(glm::vec3 pos)
{
    _cameraPos = pos;
}

void Camera::OnScreenAspectChange(float aspect)
{
    UpdateProjection(aspect); 
}

void Camera::SetZoomLevel(float zoomLevel)
{
    _zoomLevel = zoomLevel;
}

