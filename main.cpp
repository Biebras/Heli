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
#include <graphics/graphics.h>
#include <graphics/camera.hpp>
#include <graphics/resources.h>
#include <graphics/sprite.hpp>
#include <graphics/quad.hpp>
#include <physics/rectangle_collider.hpp>
#include <physics/circle_collider.hpp>

void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 500;
float zoomLevel = 1;

glm::vec3 cameraPos(0, 0, 0);
glm::vec3 circlePos(0, 0, 0);

//time 
float deltaTime = 0;
float lastFrame = 0;

GameObject* quad1 = new GameObject();
GameObject* quad2 = new GameObject();

int main()
{
    Game& game = Game::Get();
    GLFWwindow *window = CreateWindow(SCR_WIDTH, SCR_HEIGHT, "Heli Engine");

    Camera *camera = new Camera(zoomLevel);
    camera->ActivateCamera();

    quad1->AddComponent(new Sprite("texture_test"));
    quad1->AddComponent(new RectangleCollider());
    quad2->transform->Position.x = 1;
    quad2->AddComponent(new Sprite("texture_test"));
    quad2->AddComponent(new CircleCollider());

    quad1->Start();
    quad2->Start();

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

        camera->UpdateProjection(ScreenAspectRatio);
        camera->SetCameraPos(cameraPos);
        //gameObject->transform->Position.x += deltaTime * 0.01f;

        // render
        // ------
        glEnable(GL_BLEND);
        //glEnable(GL_FRAMEBUFFER_SRGB);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(WHITE_COLOR.x, WHITE_COLOR.y, WHITE_COLOR.z, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        quad1->Update();
        quad2->Update();

        DrawCircle(glm::vec3(0, 2, 0), 0.5f, 0.15f, RED_COLOR, BLACK_COLOR);
        DrawRectnagle(glm::vec3(1, 2, 0), glm::vec2(1), 0.15f, BLUE_COLOR, BLACK_COLOR, glm::vec4(0.3f, 1, 0.5f, abs(glm::sin(glfwGetTime()))));

        DrawGrid();
        quad2->Draw();
        quad1->Draw();
        //DrawCircle(circlePos, 1, 0.025, BLUE_COLOR, BLACK_COLOR);

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
        quad1->transform->Position.x += 2 * deltaTime; 

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        quad1->transform->Position.x -= 2 * deltaTime; 

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        quad1->transform->Position.y += 2 * deltaTime; 

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        quad1->transform->Position.y -= 2 * deltaTime; 
}
