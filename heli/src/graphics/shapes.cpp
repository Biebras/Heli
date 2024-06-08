#include <graphics/camera.hpp>
#include <graphics/circle.hpp>
#include <graphics/rectangle.hpp>
#include <graphics/shapes.h>
#include <graphics/resources.h>
#include <graphics/quad.hpp>
#include <core/game.hpp>
#include <core/event_manager.h>
#include <core/game_object.hpp>
#include <core/component.hpp>

Circle* circle;
Rectangle* rectangle;
GameObject* grid;

void InitShapes()
{
    circle = new Circle();
    rectangle = new Rectangle();
    grid = new GameObject();

    grid->AddComponent(static_cast<Component*>(new Quad("heli_grid")));

    circle->Start();
    rectangle->Start();
    grid->Start();
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

void PositionQuad(GameObject* object, glm::vec2 topLeftCorner, glm::vec2 botRightCorner)
{
    glm::vec2 center = glm::vec2((topLeftCorner.x + botRightCorner.x) / 2, (topLeftCorner.y + botRightCorner.y) / 2);
    float xScale = abs(botRightCorner.x - topLeftCorner.x);
    float yScale = abs(topLeftCorner.y - botRightCorner.y);

    object->transform->Position = glm::vec3(center.x, center.y, 0);
    object->transform->Scale = glm::vec3(xScale, yScale, 0);
}

void DrawRectangle(glm::vec2 topLeftCorner, glm::vec2 botRightCorner, float thickness, glm::vec4 baseColor, glm::vec4 outlineColor, glm::vec4 cornerRadius)
{
    PositionQuad(rectangle, topLeftCorner, botRightCorner);

    rectangle->Thickness = thickness;
    rectangle->BaseColor = baseColor;
    rectangle->OutlineColor = outlineColor;
    rectangle->CornerRadius = cornerRadius;

    rectangle->Update();
    rectangle->Draw();
}

void DrawGrid()
{
    Camera* camera = Game::Get().ActiveCamera;
    glm::vec2 topLeft = camera->ScreenToWorldPoint(glm::vec2(-1, 1)); 
    glm::vec2 botRight = camera->ScreenToWorldPoint(glm::vec2(1, -1)); 
    PositionQuad(grid, topLeft, botRight);

    grid->Update();
    grid->Draw();
}
