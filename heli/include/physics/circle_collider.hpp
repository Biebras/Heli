#ifndef CIRCLE_COLLIDER_HPP
#define CIRCLE_COLLIDER_HPP

#include <physics/collider.hpp>

class CircleCollider : public Collider
{
    public:
        CircleCollider() = default;
        ColliderType GetColliderType() override
        {
            return CIRCLE_COLLIDER;
        }
        void Draw() override;
        float Radius = 0.5f;
};

#endif
