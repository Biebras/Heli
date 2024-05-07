#include <graphics/circle.hpp>
#include <graphics/quad.hpp>
#include <graphics/resources.h>
#include <core/component.hpp>

Circle::Circle() : GameObject()
{
    _circleShader = GetShader("heli_circle"); 
    AddComponent(static_cast<Component*>(new Quad("heli_circle"))); 
}

Circle::~Circle()
{
    delete _circleShader;
}

void Circle::SetRadius(float radius)
{
    transform->Scale = glm::vec3(radius, radius, radius);
}

void Circle::SetThickness(float thickness)
{
    _thickness = thickness;
}

void Circle::SetBaseColor(glm::vec4 baseColor)
{
    _baseColor = baseColor;
}

void Circle::SetOutlineColor(glm::vec4 outlineColor)
{
    _outlineColor = outlineColor;
}

void Circle::Draw()
{
    _circleShader->Use();
    _circleShader->SetVector4("BaseColor", _baseColor); 
    _circleShader->SetVector4("OutlineColor", _outlineColor);
    _circleShader->SetFloat("Thickness", _thickness);
    GameObject::Draw();
}
