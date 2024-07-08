#include <physics/circle_collider.hpp>
#include <graphics/shapes.h>
#include <core/component.hpp>
#include <core/colors.h>

void CircleCollider::Draw()
{
    if(!Debug)
        return;

    Component* comp = static_cast<Component*>(this);
    glm::vec3 pos = comp->parent->transform->Position;

    if(IsColliding() == true)
        DrawCircle(pos, Radius, 0.1f, TRANSPARENT_COLOR, GREEN_COLOR);
    else
        DrawCircle(pos, Radius, 0.1f, TRANSPARENT_COLOR, RED_COLOR);
}
