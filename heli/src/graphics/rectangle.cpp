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
    _rectangleShader->SetFloat("Thickness", Thickness);
    _rectangleShader->SetVector4("BaseColor", BaseColor);
    _rectangleShader->SetVector4("OutlineColor", OutlineColor);
    _rectangleShader->SetVector4("CornerRadius", CornerRadius);

    GameObject::Draw();
}
