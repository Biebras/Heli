#include <graphics/sprite.hpp>
#include <graphics/resources.h>

Sprite::Sprite(const char* textureName) : Quad("heli_sprite")
{
    _texture = GetTexture(textureName);

    Shader->Use();
    _texture->Bind();
    Shader->SetInt("BaseTexture", 0);
}

void Sprite::Draw() 
{
    Quad::Draw();
}

