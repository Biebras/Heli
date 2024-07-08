#include "glm/geometric.hpp"
#include <physics/collider.hpp>
#include <physics/rectangle_collider.hpp>
#include <physics/circle_collider.hpp>
#include <math/math.hpp>

bool Collider::IsColliding()
{
    std::vector colliders = GetColliders();
    Component* current = static_cast<Component*>(this);
    ColliderType currentType = GetColliderType();

    for(auto collider : colliders)
    {
        if(collider == this)
            continue;

        ColliderType otherType = collider->GetColliderType();

        if(currentType == RECTANGLE_COLLIDER && otherType == RECTANGLE_COLLIDER)
        {
            if(CollisionRectWithRect(collider))
                return true;
        }
        else if(currentType == CIRCLE_COLLIDER && otherType == CIRCLE_COLLIDER)
        {
            if(CollisionCircleWithCircle(collider))
                return true;
        }
        else if(currentType == CIRCLE_COLLIDER && otherType == RECTANGLE_COLLIDER)
        {
            if(CollisionCircleWithRect(this, collider))
                return true;
        }
        else if(currentType == RECTANGLE_COLLIDER && otherType == CIRCLE_COLLIDER)
        {
            if(CollisionCircleWithRect(collider, this))
                return true;
        }
    }

    return false;
}

bool Collider::CollisionRectWithRect(Collider* otherColl)
{
    Component* current = static_cast<Component*>(this);
    Component* other = static_cast<Component*>(otherColl); 
    RectangleCollider* rect = static_cast<RectangleCollider*>(this);
    RectangleCollider* otherRect = static_cast<RectangleCollider*>(otherColl);

    glm::vec3 currentPos = current->parent->transform->Position;
    glm::vec2 scale = rect->BorderScale;
    glm::vec3 otherPos = other->parent->transform->Position;
    glm::vec2 otherScale = otherRect->BorderScale;

    bool collisionX = currentPos.x + scale.x >= otherPos.x &&
        otherPos.x + otherScale.x >= currentPos.x;

    bool collisionY = currentPos.y + scale.y >= otherPos.y &&
        otherPos.y + otherScale.y >= currentPos.y;

    return collisionX && collisionY;
}

bool Collider::CollisionCircleWithCircle(Collider* otherColl)
{
    Component* current = static_cast<Component*>(this);
    Component* other = static_cast<Component*>(otherColl); 
    CircleCollider* otherCircle = static_cast<CircleCollider*>(otherColl);
    CircleCollider* circle = static_cast<CircleCollider*>(this);
    glm::vec2 pos = current->parent->transform->Position;
    glm::vec2 otherPos = other->parent->transform->Position;

    float maxDistance = (circle->Radius + otherCircle->Radius) / 2;
    float distance = VectorDistance(pos, otherPos);

    return distance <= maxDistance;
}

bool Collider::CollisionCircleWithRect(Collider* circle, Collider* rect)
{
    CircleCollider* circCol = static_cast<CircleCollider*>(circle); 
    RectangleCollider* rectCol = static_cast<RectangleCollider*>(rect);
    Component* circComp = static_cast<Component*>(circle);
    Component* rectComp = static_cast<Component*>(rect);

    glm::vec2 circPos = circComp->parent->transform->Position;
    glm::vec2 rectPos = rectComp->parent->transform->Position;

    glm::vec2 halfRect(rectCol->BorderScale.x / 2, rectCol->BorderScale.y / 2);
    glm::vec2 difference = circPos - rectPos;
    glm::vec2 clamped = glm::clamp(difference, -halfRect, halfRect);
    glm::vec2 closest = rectPos + clamped;
    difference = closest - circPos;

    return glm::length(difference) <= circCol->Radius;
}
