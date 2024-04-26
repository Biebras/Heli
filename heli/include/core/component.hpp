#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class GameObject;

class Component
{
    public:
        virtual ~Component() = default;
        virtual void Start() {}
        virtual void Update() {}
        virtual void Draw() {}

        GameObject* parent;
};

#endif
