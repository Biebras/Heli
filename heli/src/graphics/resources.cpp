#include <graphics/resources.h>
#include <iostream>
#include <ostream>
#include <unordered_map>

std::unordered_map<const char*, Shader*> Shaders;
std::unordered_map<const char*, Texture*> Textures;

void LoadHeliResources()
{
    CreateShader("heli_circle", "./heli/assets/shaders/circle.glsl");
    CreateShader("heli_rectangle", "./heli/assets/shaders/rectangle.glsl");
    CreateShader("heli_sprite", "./heli/assets/shaders/sprite.glsl");
    CreateShader("heli_grid", "./heli/assets/shaders/grid.glsl");

    CreateTexture("texture_test", "./heli/assets/images/gruvbox-icon.png");
}

void CreateTexture(const char* textureName, const char* texturePath)
{
    if(Textures.count(textureName) != 0)
    {
        std::cout << "Can't create texture with name " << textureName << " as there is texture with this name" << std::endl;
        return;
    }

    Texture* texture = new Texture(texturePath);
    Textures[textureName] = texture;
}

void CreateShader(const char* shaderName, const char* shaderPath)
{
    if(Textures.count(shaderName) != 0)
    {
        std::cout << "Can't create shader with name " << shaderName << " as there is shader with this name" << std::endl;
        return;
    }
    
    Shader* shader = new Shader(shaderPath);
    Shaders[shaderName] = shader;
}

Texture* GetTexture(const char* textureName)
{
    if(Textures.count(textureName) == 0)
    {
        std::cout << "Can't find texture with name " << textureName << std::endl;
        return nullptr;
    }

    return Textures[textureName];
}

Shader* GetShader(const char* shaderName)
{
    if(Shaders.count(shaderName) == 0)
    {
        std::cout << "Can't find shader with name " << shaderName << std::endl;
        return nullptr;
    }

    return Shaders[shaderName];
}
