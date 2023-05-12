#pragma once

#include "Component.hpp"

namespace Heli
{
    class VelocityComponent : public Component
    {
        public:
            float directionX;
            float directionY;
    };
}