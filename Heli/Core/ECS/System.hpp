#pragma once

#include <vector>

#include "ClassTypeId.hpp"
#include "Entity.hpp"
#include "../Logging/Debug.hpp"

namespace Heli
{
    class SystemBase
    {
        public:
            virtual ~SystemBase() {}
            virtual void OnUpdate(std::vector<Entity*> entities) = 0;
            std::vector<TypeId> GetRequiredComponents() {return requiredComponents;}
            TypeId TypeID = UNDEFINED_TYPE;
            bool Enabled = true;
        protected:
            // Define a vector of required component types
            std::vector<TypeId> requiredComponents;
    };

    template<typename... ComponentClasses>
    class System : public SystemBase
    {
        public:
            System()
            {
                requiredComponents = {GetTypeId<ComponentClasses>()...};
            }
            ~System() {};
    };
}