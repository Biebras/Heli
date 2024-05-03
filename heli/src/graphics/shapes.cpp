#include <graphics/circle.hpp>
#include <graphics/rectangle.hpp>
#include <graphics/shapes.h>
#include <core/event_manager.h>

Circle* circle;
Rectangle* rectangle;

void InitShapes()
{
    circle = new Circle();
    rectangle = new Rectangle();

    circle->Start();
    circle->Start();
}

void DrawCircle(glm::vec3 position, float radius, float thickness, glm::vec4 baseColor, glm::vec4 outlineColor)
{
    circle->transform->Position = position;
    circle->SetRadius(radius);
    circle->SetThickness(thickness);
    circle->SetBaseColor(baseColor);
    circle->SetOutlineColor(outlineColor);

    circle->Update();

    circle->Draw();
}

void DrawRectangle(glm::vec3 position, glm::vec4 baseColor)
{
    rectangle->transform->Position = position;
    rectangle->SetBaseColor(baseColor);

    rectangle->Update();

    rectangle->Draw();
}
