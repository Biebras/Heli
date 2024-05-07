#include <graphics/rectangle.hpp>
#include <graphics/resources.h>
#include <graphics/quad.hpp>

Rectangle::Rectangle() : GameObject()
{
    _rectangleShader = GetShader("heli_rectangle"); 
    AddComponent(static_cast<Component*>(new Quad("heli_rectangle"))); 
}

void Rectangle::Draw()
{
    _rectangleShader->Use();
    _rectangleShader->SetVector4("BaseColor", _baseColor);
    GameObject::Draw();
}

void Rectangle::SetBaseColor(glm::vec4 baseColor)
{
    _baseColor = baseColor;
}
