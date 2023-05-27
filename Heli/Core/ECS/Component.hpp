#pragma once

#include "ClassTypeId.hpp"

namespace Heli
{
    class Entity;

    class Component
    {
        public:
            ~Component() {};
            TypeId TypeID = UNDEFINED_TYPE;
            Entity* ParentEntity = nullptr;
    };
}
