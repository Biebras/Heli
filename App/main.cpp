#include <iostream>

#include "Entity.hpp"
#include "MovementSystem.hpp"
#include "TransformComponent.hpp"
#include "Math.hpp"

using namespace std;

int main()
{
    Entity entity1;
    TransformComponent transform1;
    transform1.position.x = 0.0f;
    transform1.position.y = 0.0f;
    entity1.AddComponent(&transform1);

    Entity entity2;
    TransformComponent transform2;
    transform2.position.x = 0.0f;
    transform2.position.y = 0.0f;
    entity2.AddComponent(&transform2);

    MovementSystem* movementSystem = new MovementSystem();

    movementSystem->AddEntity(&entity1);
    movementSystem->AddEntity(&entity2);

    // Later this will be while loop
    for (int i = 0; i < 10; i++)
    {
        movementSystem->Update();
    }

    return 0;
}
