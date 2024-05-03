#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <graphics/shader.h>
#include <core/game_object.hpp>
#include <glm/glm.hpp>

class Rectangle : public GameObject
{
    public:
        Rectangle();
        ~Rectangle();
        void Draw() override;
        void SetBaseColor(glm::vec4 baseColor);
    private:
        Shader* _rectangleShader;
        glm::vec4 _baseColor = glm::vec4(1);
};

#endif

