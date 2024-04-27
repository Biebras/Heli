#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <core/game.hpp>
#include <core/game_object.hpp>
#include <core/component.hpp>
#include <graphics/quad.hpp>
#include <graphics/shader.h>
#include <graphics/graphics.h>
#include <graphics/camera.hpp>

void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 500;
float zoomLevel = 0.5f;

glm::vec3 cameraPos(0, 0, 0);
glm::vec3 quadPos(0, 0, 0);

//time 
float deltaTime = 0;
float lastFrame = 0;

GameObject *quad = new GameObject();

int main()
{
    Game& game = Game::Get();
    GLFWwindow *window = CreateWindow(SCR_WIDTH, SCR_HEIGHT, "Custom Window");

    Shader shader("./heli/assets/shaders/circle.glsl");
    Camera camera(zoomLevel);
    camera.ActivateCamera();

    Quad *quadComponent = new Quad(&shader);
    quad->AddComponent(static_cast<Component*>(quadComponent));
    
    quad->Start();

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

        camera.SetCameraPos(cameraPos);

        // render
        // ------
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(0.2f, 0.3f, 0.3f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        quad->Update();

        quad->Draw();
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    delete quad;

    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
       quad->transform->Position.x += 1 * deltaTime; 

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
       quad->transform->Position.x -= 1 * deltaTime; 
}
