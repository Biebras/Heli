#ifndef RECTANGLE_COLLISION_HPP
#define RECTANGLE_COLLISION_HPP

#include <glm/glm.hpp>
#include <physics/collider.hpp>

class RectangleCollider : public Collider 
{
    public:
        RectangleCollider() = default;
        ColliderType GetColliderType() override
        {
            return RECTANGLE_COLLIDER;
        }
        void Draw() override;
        glm::vec2 BorderScale = glm::vec2(1);
};

#endif
