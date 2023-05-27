#pragma once

#include "../ECS/ClassTypeId.hpp"
#include "../ECS/System.hpp"
#include "../Logging/Debug.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/VelocityComponent.hpp"

namespace Heli
{
    class ShitSystem : public System<TransformComponent>
    {
        public:
            virtual void OnUpdate(std::vector<Entity*> entities) override
            {
                LOG("Hello this is shit system and I have %d entities", entities.size());
            }
    };
}
