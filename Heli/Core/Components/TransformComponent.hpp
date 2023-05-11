#pragma once

#include "Component.hpp"

namespace Heli
{
    class TransformComponent : public Component
    {
        public:
            float positionX;
            float positionY;
    };
}