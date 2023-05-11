#pragma once

#include <unordered_map>
#include <typeindex>

#include "Component.hpp"

namespace Heli
{
    class Entity
    {
        public:
            Entity() {};
            ~Entity() 
            {
                for (auto& component : components)
                {
                    delete component.second;
                }
            };
            template <typename T>
            void AddComponent(T* component);
            template <typename T>
            T* GetComponent();

        private:
            std::unordered_map<std::type_index, Component*> components;
    };

    template <typename T>
    void Entity::AddComponent(T* component)
    {
        components[typeid(T)] = component;
    }

    template <typename T>
    T* Entity::GetComponent()
    {
        return static_cast<T*>(components[typeid(T)]);
    }
}