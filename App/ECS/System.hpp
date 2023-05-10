#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>

#include "Entity.hpp"

class System
{
    public:
        System() {};
        ~System() {};
        void AddEntity(Entity* entity);
        virtual void Update() = 0;

    protected:
        std::vector<Entity*> entities;
};

#endif