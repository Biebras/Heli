#ifndef _MOVEMENTSYSTEM_CPP_
#define _MOVEMENTSYSTEM_CPP_

#include <iostream>

#include "MovementSystem.hpp"

TransformComponent* transform;

void MovementSystem::Update()
{
    for (Entity* entity : entities)
    {
        transform = entity->GetComponent<TransformComponent>();

        if (transform)
        {
            std::cout << "Entity: " << entity << " Position: " << transform->position.x << ", " << transform->position.y << std::endl;
            transform->position.x += 0.1f;
            transform->position.y += 0.1f;
        }
    }
}

#endif