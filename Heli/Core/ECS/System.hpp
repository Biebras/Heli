#pragma once

#include <vector>

#include "ClassTypeId.hpp"
#include "../Logging/Debug.hpp"

namespace Heli
{
    template<typename... ComponentClasses>
    class System
    {
        public:
            System() : requiredComponents{GetTypeId<ComponentClasses>()...} {}
            ~System() {};
            virtual void OnUpdate(const std::vector<Entity>& entities) = 0;
            TypeId TypeID = UNDEFINED_TYPE;

        protected:
            // Define a vector of required component types
            std::vector<TypeId> requiredComponents;
    };
}