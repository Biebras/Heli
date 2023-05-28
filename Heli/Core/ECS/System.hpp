#pragma once

#include <vector>

#include "ClassTypeId.hpp"
#include "Entity.hpp"
#include "../Logging/Debug.hpp"

namespace Heli
{
    /// @brief Base class for all systems in the Heli engine.
    class SystemBase
    {
        public:
            virtual ~SystemBase() {}

            /// @brief Pure virtual function to update the system with a vector of entities.
            /// @param entities Vector of entities to update the system with.
            virtual void OnUpdate(std::vector<Entity*> entities) = 0;

            /// @brief Returns a vector of required component types for this system.
            /// @return Vector of required component types.
            std::vector<TypeId> GetRequiredComponents() {return requiredComponents;}

            /// Type ID of the system.
            TypeId TypeID = UNDEFINED_TYPE; 
            /// Whether the system is enabled or not.
            bool Enabled = true; 

        protected:
            /// Vector of required component types for this system.
            std::vector<TypeId> requiredComponents; 
    };

    /// @brief Template class for systems in the Heli engine.
    /// @tparam ComponentClasses Component classes required by this system.
    template<typename... ComponentClasses>
    class System : public SystemBase
    {
        public:
            /// @brief Constructor. Initializes the required components vector with the provided component classes.
            System()
            {
                requiredComponents = {GetTypeId<ComponentClasses>()...};
            }

            ~System() {};
    };
}
