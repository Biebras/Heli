#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>

#include <core/component.hpp>

class GameObject
{
    public:
        GameObject() = default;
        ~GameObject() = default;
        void AddComponent(Component* component);
        void Update();
        void Draw();
    private:
        std::vector<Component*> _components;

};

#endif
