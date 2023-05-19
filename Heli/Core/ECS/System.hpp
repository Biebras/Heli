#pragma once

#include <vector>

#include "ClassTypeId.hpp"
#include "../Logging/Debug.hpp"
#include "Entity.hpp"

namespace Heli
{
    class SystemBase
    {
    public:
        virtual ~SystemBase() {}
        virtual void OnUpdate(const std::vector<Entity>& entities) = 0;
        TypeId TypeID = UNDEFINED_TYPE;
    };

    template<typename... ComponentClasses>
    class System : public SystemBase
    {
        public:
            System() : requiredComponents{GetTypeId<ComponentClasses>()...} {}
            ~System() {};

        protected:
            // Define a vector of required component types
            std::vector<TypeId> requiredComponents;
    };
}