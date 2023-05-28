#pragma once

#include "../ECS/ClassTypeId.hpp"
#include "../ECS/System.hpp"
#include "../Logging/Debug.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/SpriteComponent.hpp"

namespace Heli
{
    class RenderingSystem : public System<PositionComponent, SpriteComponent>
    {
        public:
            virtual void OnUpdate(std::vector<Entity*> entities) override
            {
                for (auto entity : entities) 
                {
                    auto position = entity->GetComponent<PositionComponent>();
                    auto sprite = entity->GetComponent<SpriteComponent>();

                    // Suppress unused variable warnings
                    (void)position;
                    (void)sprite;

                    // Render sprite at position here
                }

                LOG("Updated sprite for %d entities", entities.size());
            }
    };
}
