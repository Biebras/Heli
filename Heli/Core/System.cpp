#include "System.hpp"

namespace Heli
{
    void System::AddEntity(Entity* entity)
    {
        entities.push_back(entity);
    }
}