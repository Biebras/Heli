#include <graphics/rectangle.hpp>
#include <graphics/quad.hpp>

Rectangle::Rectangle() : GameObject()
{
    _rectangleShader = new Shader("./heli/assets/shaders/rectangle.glsl");
    AddComponent(static_cast<Component*>(new Quad(_rectangleShader))); 
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
