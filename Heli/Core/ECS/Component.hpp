#pragma once

#include "ClassTypeId.hpp"

namespace Heli
{
    class Entity;

    /// @brief Base class for components
    class Component
    {
        public:
            ~Component() {};

            /// @brief Unique type ID of the component
            TypeId TypeID = UNDEFINED_TYPE;

            /// @brief Pointer to the parent entity of the component
            Entity* ParentEntity = nullptr;
    };
}
