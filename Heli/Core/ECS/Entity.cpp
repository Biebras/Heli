#include "Entity.hpp"

namespace Heli
{
    Entity::~Entity()
    {
        components.clear();
    }

    /// @brief Checks if the entity contains a component of the given type ID
    /// @param typeID The type ID of the component to check for
    /// @return `true` if the entity contains the component, `false` otherwise
    bool Entity::ContainsComponent(TypeId typeID)
    {
        return components.find(typeID) != components.end();
    }
}
