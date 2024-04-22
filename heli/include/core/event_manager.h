#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <graphics/camera.hpp>
#include <core/event.hpp>

struct CameraEvents
{
    Event<Camera*> OnActivate; 
};

struct WindowEvents
{
    Event<int, int> OnSizeChange;
    Event<float> OnAspectRatioChange;
};

extern CameraEvents cameraEvents;
extern WindowEvents windowEvents;

#endif
