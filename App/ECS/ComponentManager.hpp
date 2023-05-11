#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include "Component.hpp"
#include "Entity.hpp"

class ComponentManager
{
public:
    template <typename T>
    T* CreateComponent(Entity entity);

    template <typename T>
    void RemoveComponent(Entity entity);

private:
    void AddComponentToEntity(Entity entity, Component* component);
};

template <typename T>
T* CreateComponent(Entity entity)
{
    T* component = new T();
    AddComponentToEntity(entity, component);
    return component;
}

template <typename T>
void RemoveComponent(Entity entity)
{
    // Remove the component from the entity
    // ...
}

void AddComponentToEntity(Entity entity, Component* component)
{
    // Add the component to the entity
    // ...
}

#endif // COMPONENT_MANAGER_HPP