#pragma once

#include <unordered_map>
#include <typeindex>

#include "ClassTypeId.hpp"
#include "Component.hpp"
#include "../Memory/MemoryManager.hpp"
#include "../Logging/Debug.hpp"

class Component;

namespace Heli
{
    /// @brief Class representing an entity
    class Entity
    {
        public:
            Entity() = default;
            ~Entity();

            template <typename T>
            void AddComponent(T* component);

            template <typename T>
            void RemoveComponent();

            template <typename T>
            T* GetComponent();

            bool ContainsComponent(TypeId typeID);

            TypeId TypeID = UNDEFINED_TYPE;

        private:
            std::unordered_map<TypeId, Component*> components;
    };

    /// @brief Adds a component to the entity
    /// @tparam T The type of the component to add
    template <typename T>
    void Entity::AddComponent(T* component)
    {
        // Check if the component was allocated
        if (component->TypeID == UNDEFINED_TYPE)
        {
            LOG_WARNING("Can't add this component as this compoent was not allocated");
            return;
        }

        // Check if the component already exists
        if (components[component->TypeID] != nullptr)
        {
            LOG_WARNING("Can't add this component to entity because it already exists!");
            return;
        }

        component->ParentEntity = this;
        components[component->TypeID] = component;
    }

    /// @brief Removes a component from the entity
    /// @tparam T The type of the component to remove
    template <typename T>
    void Entity::RemoveComponent()
    {
        int typeID = GetTypeId<T>();

        // Check if the component exists
        if (components[typeID] == nullptr)
        {
            LOG_WARNING("Can't remove this component from entity because it doesn't exist!");
            return;
        }

        Component* component = components[typeID];
        component->ParentEntity = nullptr;
        components.erase(typeID);
    }

    /// @brief Gets a component from the entity
    /// @tparam T The type of the component to get
    /// @return A pointer to the requested component, or `nullptr` if it doesn't exist
    template <typename T>
    T* Entity::GetComponent()
    {
        int typeID = GetTypeId<T>();

        // Check if the component exists
        if (components[typeID] == nullptr)
        {
            LOG_WARNING("Can't get this component from entity because it doesn't exist!");
            return nullptr;
        }

        return static_cast<T*>(components[typeID]);
    }
}
