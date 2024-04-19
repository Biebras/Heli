#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
    public:
        Camera();
        Camera(float zoomLevel);
        ~Camera();
        glm::mat4 GetVP();
        void UpdateProjection(int aspectRatio);
        void OnScreenSizeUpdate(int width, int height);
        void SetZoomLevel(float zoomLevel);

    private:
        int _onScreenUpdateEventId;
        float _zoomLevel;
        glm::mat4 _projection    = glm::mat4(1.0f);
};

#endif
