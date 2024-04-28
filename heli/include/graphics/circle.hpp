#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include<glm/glm.hpp>

#include <core/game_object.hpp>
#include <graphics/shader.h>


class Circle : public GameObject
{
    public:
        Circle();
        ~Circle();
        void SetRadius(float radius);
        void SetThickness(float thickness);
        void SetBaseColor(glm::vec4 baseColor);
        void SetOutlineColor(glm::vec4 outlineColor);
        void Draw() override;
    private:
        Shader* _circleShader;
        float _thickness;
        glm::vec4 _baseColor;
        glm::vec4 _outlineColor;
};

#endif

