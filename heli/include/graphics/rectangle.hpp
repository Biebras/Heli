#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <graphics/shader.h>
#include <core/game_object.hpp>
#include <glm/glm.hpp>

class RectangleCollision;

class Rectangle : public GameObject
{
    public:
        Rectangle();
        ~Rectangle();
        void Draw() override;
        float Thickness;
        glm::vec4 BaseColor = glm::vec4(1);
        glm::vec4 OutlineColor = glm::vec4(0, 0, 0, 1);
        glm::vec4 CornerRadius = glm::vec4(0);
    private:
        Shader* _rectangleShader;
        void CollisionWithRectangle(RectangleCollision* other);
};

#endif

