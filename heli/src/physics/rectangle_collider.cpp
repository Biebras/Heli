#include <physics/rectangle_collider.hpp>
#include <graphics/shapes.h>
#include <core/component.hpp>
#include <core/colors.h>

void RectangleCollider::Draw()
{ 
    if(!Debug)
        return;

    Component* comp = static_cast<Component*>(this);
    glm::vec3 pos = comp->parent->transform->Position;

    if(IsColliding() == true)
        DrawRectnagle(pos, BorderScale, 0.1, TRANSPARENT_COLOR, GREEN_COLOR, glm::vec4(0)); 
    else
        DrawRectnagle(pos, BorderScale, 0.1, TRANSPARENT_COLOR, RED_COLOR, glm::vec4(0)); 

}
