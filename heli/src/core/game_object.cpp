#include <core/game_object.hpp>

void GameObject::Update()
{
    for (Component* component : _components)
    {
        component->Update();
    }
}

void GameObject::Draw()
{
    for (Component* component : _components)
    {
        component->Draw();
    }
}

void GameObject::AddComponent(Component* component)
{
   _components.push_back(component); 
}
