#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <core/component.hpp>

class Transform : public Component
{
    public:
        Transform() = default;
        ~Transform() = default; 
        glm::mat4 GetModel()
        {
            glm::mat4 model = glm::mat4(1);

            model = glm::translate(model, Position);
            model = glm::scale(model, Scale);
            model = glm::rotate(model, glm::radians(RotationZ), glm::vec3(0, 0, 1));

            return model;
        }
        glm::vec3 Position = glm::vec3(0);
        float RotationZ = 0;
        glm::vec3 Scale = glm::vec3(1);
};

#endif
