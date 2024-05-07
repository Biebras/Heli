#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "glm/fwd.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
    public:
        Camera();
        Camera(float zoomLevel);
        ~Camera();
        void ActivateCamera();
        void SetCameraPos(glm::vec3 pos);
        glm::mat4 GetViewMatrix();
        glm::mat4 GetVP();
        void UpdateProjection(float aspectRatio);
        void OnScreenAspectChange(float aspect);
        void SetZoomLevel(float zoomLevel);
        glm::vec2 ScreenToWorldPoint(glm::vec2 screenPos);

    private:
        int _onScreenAspectUpdateId;
        float _zoomLevel;
        glm::vec3 _cameraPos = glm::vec3(1.0f); 
        glm::mat4 _projection = glm::mat4(1.0f);
};

#endif
