#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <core/game.hpp>
#include <core/game_object.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.h>
#include <graphics/graphics.h>
#include <graphics/camera.hpp>

#include <iostream>
#include <vector>

void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 500;
float zoomLevel = 20;

glm::vec3 cameraPos(0, 0, 0);
glm::vec3 quadPos(0, 0, 0);
glm::mat4 projection = glm::mat4(1);

//time 
float deltaTime = 0;
float lastFrame = 0;

int main()
{
    Game& game = Game::Get();
    GLFWwindow *window = CreateWindow(SCR_WIDTH, SCR_HEIGHT, "Custom Window");

    GameObject *quad = new GameObject();

    Shader shader("./assets/shaders/test.glsl");
    Camera camera(12);
    camera.ActivateCamera();
    Renderer *quadRenderer = new Renderer();

    std::vector<float> vertices = 
    {
        -0.5f, -0.5f, 0.0f,  // Bottom left
        -0.5f,  0.5f, 0.0f,  // Top left
         0.5f, -0.5f, 0.0f,  // Bottom right
         0.5f,  0.5,  0.0f   // Top Right
    };

    std::vector<uint> indices = 
    {
        0, 2, 1,
        1, 2, 3
    };

    quadRenderer->CreateMesh(vertices, indices);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Update
        // -----
        processInput(window);

        // transformations
        // create transformations
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, quadPos);

        camera.SetCameraPos(cameraPos);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Use();
        shader.SetMatrix4("MVP", game.ActiveCamera->GetVP() * model);
        quadRenderer->Draw(shader);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    delete quadRenderer;

    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
