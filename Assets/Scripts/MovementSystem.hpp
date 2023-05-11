#pragma once

#include "System.hpp"
#include "TransformComponent.hpp"

using namespace Heli;

class MovementSystem : public System
{
    public:
        void Update() override;
};