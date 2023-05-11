#include <iostream>

#include "MovementSystem.hpp"

void MovementSystem::Update()
{
    for (Entity* entity : entities)
    {
        TransformComponent* transform = entity->GetComponent<TransformComponent>();

        if (transform)
        {
            float x = transform->positionX;
            float y = transform->positionY;
            std::cout << "Entity: " << entity << " Position: " << x << ", " << y << std::endl;
            transform->positionX += 0.1f;
            transform->positionY += 0.1f;
        }
    }
}