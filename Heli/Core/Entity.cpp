#include "Entity.hpp"

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