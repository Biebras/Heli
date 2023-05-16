#pragma once

#include <unordered_map>
#include <typeindex>

#include "Component.hpp"
#include "../Memory/MemoryManager.hpp"

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
                    auto& pool = instance.GetPool(component.second->TypeId);
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

            TypeId TypeId;

        private:
            std::unordered_map<std::type_index, Component*> components;
    };

    template <typename T>
    void Entity::AddComponent(T* component)
    {
        // Cheack if the component already exists
        if (components.find(typeid(T)) != components.end())
        {
            LogManager::LogWarning("Can't add this component to entity because it already exists!", typeid(T).name());
            return;
        }

        components[typeid(T)] = component;
    }

    template <typename T>
    void Entity::RemoveComponent()
    {
        // Check if the component exists
        if (components.find(typeid(T)) == components.end())
        {
            LogManager::LogWarning("Can't remove this component from entity because it doesn't exist!", typeid(T).name());
            return;
        }

        components.erase(typeid(T));
    }

    template <typename T>
    T* Entity::GetComponent()
    {
        return static_cast<T*>(components[typeid(T)]);
    }
}