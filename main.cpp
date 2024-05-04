#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb_image.h>

#include <core/game.hpp>
#include <core/game_object.hpp>
#include <core/component.hpp>
#include <core/colors.h>
#include <graphics/shapes.h>
#include <graphics/quad.hpp>
#include <graphics/shader.h>
#include <graphics/graphics.h>
#include <graphics/texture.hpp>
#include <graphics/camera.hpp>

void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 500;
float zoomLevel = 10;

glm::vec3 cameraPos(0, 0, 0);
glm::vec3 circlePos(0, 0, 0);

//time 
float deltaTime = 0;
float lastFrame = 0;

int main()
{
    Game& game = Game::Get();
    GLFWwindow *window = CreateWindow(SCR_WIDTH, SCR_HEIGHT, "Custom Window");

    Camera camera(zoomLevel);
    camera.ActivateCamera();

    GameObject *gameObject = new GameObject();
    gameObject->transform->Scale = glm::vec3(2, 2, 2);
    Shader *spriteShader = new Shader("./heli/assets/shaders/sprite.glsl");
    Texture *texture = new Texture("./heli/assets/images/gruvbox-icon.png");
    Quad *quad = new Quad(spriteShader);
    gameObject->AddComponent(static_cast<Component*>(quad));

    gameObject->Start();

    spriteShader->Use();
    texture->Bind();
    spriteShader->SetInt("BaseTexture", 0);

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
        glClearColor(WHITE_COLOR.x, WHITE_COLOR.y, WHITE_COLOR.z, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        gameObject->Update();

        DrawCircle(circlePos, 7, 0.025, BLUE_COLOR, BLACK_COLOR);
        gameObject->Draw();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------

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
       circlePos.x += 1 * deltaTime; 

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
       circlePos.x -= 1 * deltaTime; 

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
       circlePos.y += 1 * deltaTime; 

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
       circlePos.y -= 1 * deltaTime; 
}
