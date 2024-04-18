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
        glm::mat4 GetVP();
        void UpdateCamera(float aspectRatio);
        void SetZoomLevel(float zoomLevel);

    private:
        float _zoomLevel;
        glm::mat4 _projection    = glm::mat4(1.0f);
};

#endif
