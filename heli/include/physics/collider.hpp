#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <glm/glm.hpp>
#include <core/component.hpp>
#include <core/transform.hpp>

#include <core/game_object.hpp>
#include <physics/collider_manager.hpp>

enum ColliderType
{
    RECTANGLE_COLLIDER = 0,
    CIRCLE_COLLIDER = 1
};

class Collider : public Component
{
    public:
        Collider() = default; 
        ~Collider() = default;
        void Start() override
        {
            AddCollider(this);
        }
        virtual bool IsColliding();
        virtual ColliderType GetColliderType() = 0;
        bool CollisionRectWithRect(Collider* otherColl);
        bool CollisionCircleWithCircle(Collider* otherColl);
        bool CollisionCircleWithRect(Collider* circle, Collider* rect);
        bool Debug = true;
};

#endif
