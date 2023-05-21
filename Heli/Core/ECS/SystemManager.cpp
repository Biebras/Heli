#include "SystemManager.hpp"

namespace Heli
{
    void SystemManager::Update()
    {
        for (auto& system : systems)
        {
            system->OnUpdate();
        }
    }
}