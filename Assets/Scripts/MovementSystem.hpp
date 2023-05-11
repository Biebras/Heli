#ifndef MOVEMENTSYSTEM_HPP
#define MOVEMENTSYSTEM_HPP

#include "System.hpp"
#include "TransformComponent.hpp"

class MovementSystem : public System
{
    public:
        void Update() override;
};

#endif