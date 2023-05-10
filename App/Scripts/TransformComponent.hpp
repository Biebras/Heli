#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP

#include "Component.hpp"
#include "Math.hpp"

class TransformComponent : public Component
{
    public:
        Vector2 position;
};

#endif