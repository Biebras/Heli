#include "SystemManager.hpp"

namespace Heli
{
    void SystemManager::Update()
    {
        for (auto& system : systems)
        {
            std::vector<Entity>* entities = new std::vector<Entity>();
            system->OnUpdate(*entities);
        }
    }
}