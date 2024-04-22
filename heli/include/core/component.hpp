#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Component
{
    public:
        virtual ~Component() {}
        virtual void Update() {};
        virtual void Draw() {}
};

#endif
