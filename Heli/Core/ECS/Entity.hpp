#pragma once

#include <unordered_map>
#include <typeindex>

#include "Component.hpp"
#include "ClassTypeId.hpp"
#include "../Memory/MemoryManager.hpp"
#include "../Logging/Debug.hpp"

namespace Heli
{
    class Entity
    {
        public:
            Entity() {};
            ~Entity() 
            {
                auto& instance = MemoryManager::GetInstance();

                for (auto& component : components)
                {
                    auto& pool = instance.GetPool(component.second->TypeID);
                    void* ptr = component.second;
                    pool.Free(ptr);
                }

                components.clear();
            };
            template <typename T>
            void AddComponent(T* component);

            template <typename T>
            void RemoveComponent();

            template <typename T>
            T* GetComponent();

            TypeId TypeID = UNDEFINED_TYPE;

        private:
            std::unordered_map<TypeId, Component*> components;
    };

    template <typename T>
    void Entity::AddComponent(T* component)
    {
        if (component->typeID == UNDEFINED_TYPE)
        {
            LOG_WARNING("Can't add this component as this compoent was not allocated");
            return;
        }

        // Cheack if the component already exists
        if (components[component->typeID] != nullptr)
        {
            LOG_WARNING("Can't add this component to entity because it already exists!");
            return;
        }

        components[component->typeID] = component;
    }

    template <typename T>
    void Entity::RemoveComponent()
    {
        int typeID = GetTypeId<T>();

        // Check if the component exists
        if (components[typeID] != nullptr)
        {
            LOG_WARNING("Can't remove this component from entity because it doesn't exist!");
            return;
        }

        components.erase(typeID);
    }

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