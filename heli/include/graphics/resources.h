#include <graphics/texture.hpp>
#include <graphics/shader.h>

void LoadHeliResources();
void CreateTexture(const char* textureName, const char* texturePath);
void CreateShader(const char* shaderName, const char* shaderPath);
Texture* GetTexture(const char* textureName);
Shader* GetShader(const char* shaderName);
