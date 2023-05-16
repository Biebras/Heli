#pragma once

#include "../ECS/Component.hpp"

namespace Heli
{
    struct TransformComponent : public Component
    {
        public:
            float positionX;
            float positionY;
    };
}