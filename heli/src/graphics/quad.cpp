#include <graphics/quad.hpp>

Quad::Quad(const char* shaderName) : Renderer(shaderName)
{
    std::vector<Vertex> vertices = 
    {
        {-0.5f, -0.5f, 0.0f, 0.0f, 0.0f},  // Bottom left
        {-0.5f,  0.5f, 0.0f, 0.0f, 1.0f},  // Top left
        {0.5f, -0.5f, 0.0f, 1.0f, 0.0f}, // Bottom right
        {0.5f,  0.5,  0.0f, 1.0f, 1.0f}   // Top Right
    };

    std::vector<uint> indices = 
    {
        0, 2, 1,
        1, 2, 3
    };
    
    Renderer::CreateMesh(vertices, indices);
}

