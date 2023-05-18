#pragma once

#include "../ECS/ClassTypeId.hpp"
#include "../ECS/System.hpp"
#include "../Logging/Debug.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/VelocityComponent.hpp"

namespace Heli
{
    class TransformSystem : public System<TransformComponent, VelocityComponent>
    {
        public:
            virtual void OnUpdate(const std::vector<Entity>& entities) override
            {
                
            }
    };
}
