#pragma once

#include "../ECS/Component.hpp"

namespace Heli
{
    struct VelocityComponent : public Component
    {
        float directionX;
        float directionY;
    };
}