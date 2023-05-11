#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <unordered_map>
#include <typeindex>

#include "Component.hpp"

class Entity
{
    public:
        Entity() {};
        ~Entity() {};
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

#endif