#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <core/game.hpp>
#include <core/game_object.hpp>
#include <core/component.hpp>
#include <core/transform.hpp>
#include <graphics/shader.h>
#include <vector>

class Renderer : public Component
{
    public:
        Renderer(Shader *shader)
        {
            _shader = shader;  
        }
        ~Renderer()
        {
            glDeleteVertexArrays(1, &_VAO);
            glDeleteBuffers(1, &_VBO);
            glDeleteBuffers(1, &_EBO);
        }
        void CreateMesh(const std::vector<float> &vertices, const std::vector<uint> &indices)
        {
            glGenVertexArrays(1, &_VAO);
            glGenBuffers(1, &_VBO);
            glGenBuffers(1, &_EBO);

            glBindVertexArray(_VAO);

            glBindBuffer(GL_ARRAY_BUFFER, _VBO);
            glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint), &indices[0], GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

            _indicesCount = indices.size();
        }

        void Draw() override
        {
            _shader->Use();
            _shader->SetMatrix4("MVP", parent->transform->GetModel() * Game::Get().ActiveCamera->GetVP());
            glBindVertexArray(_VAO);
            glDrawElements(GL_TRIANGLES, _indicesCount, GL_UNSIGNED_INT, 0);
        }
    private:
        Shader* _shader;
        unsigned int _VAO, _VBO, _EBO; 
        int _indicesCount;
};

#endif