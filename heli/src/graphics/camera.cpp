#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"
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

glm::mat4 Camera::GetViewMatrix()
{
    glm::mat4 view = glm::mat4(1);
    view = glm::translate(view, _cameraPos);

    return view;
}

glm::mat4 Camera::GetVP()
{
    return _projection * GetViewMatrix();
}

void Camera::UpdateProjection(float aspectRatio)
{
    float top = 10.f / 2;
    float right = top * aspectRatio;

    _projection  = glm::ortho(-right, right, -top, top, -100.0f, 100.0f);
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

glm::vec2 Camera::ScreenToWorldPoint(glm::vec2 screenPos)
{
    glm::mat4 invMatrix = glm::inverse(GetVP()); 
    glm::vec4 pos = invMatrix * glm::vec4(screenPos.x, screenPos.y, 0, 1);
    return glm::vec2(pos.x, pos.y);
}




