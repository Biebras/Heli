#pragma once

#include <vector>

#include "Entity.hpp"

namespace Heli
{
    class System
    {
        public:
            System() {};
            ~System() {};
            void AddEntity(Entity* entity);
            virtual void OnUpdate() = 0;

        protected:
            std::vector<Entity*> entities;
    };
}