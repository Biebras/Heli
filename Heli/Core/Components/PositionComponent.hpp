#pragma once

#include "../ECS/Component.hpp"

namespace Heli
{
    struct PositionComponent : public Component 
    {
        float x;
        float y;
    };
}