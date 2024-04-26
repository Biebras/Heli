#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <core/transform.hpp>
#include <core/component.hpp>

#include <vector>

class GameObject
{
    public:
        GameObject();
        ~GameObject();
        void Start();
        void Update();
        void Draw();
        void AddComponent(Component* component);
        template<typename T>
        T* GetComponent()
        {
            for(auto c : _components)
            {
                T* component = dynamic_cast<T*>(c);
                if(component != nullptr)
                    return component;
            }

            return nullptr;
        }

        Transform *transform;
    private:
        std::vector<Component*> _components;
};

#endif
