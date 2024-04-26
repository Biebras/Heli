#include <core/game_object.hpp>

GameObject::GameObject()
{
    transform = new Transform();

    AddComponent(transform);
}

GameObject::~GameObject()
{
    for(auto component : _components)
    {
        delete component;
    }

    _components.clear();
}

void GameObject::Start()
{
    for (Component* component : _components)
    {
        component->Start();
    }
}

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
    component->parent = this;
   _components.push_back(component); 
}
