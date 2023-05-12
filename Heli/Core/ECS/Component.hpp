#pragma once

#include "ClassTypeId.hpp"

namespace Heli
{
    class Component
    {
        public:
            ~Component() {};
            TypeId TypeId;
    };
}
