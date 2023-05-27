#include "SystemManager.hpp"
#include "Entity.hpp"

namespace Heli
{
    void SystemManager::Update()
    {
        auto& poolManager = MemoryManager::GetInstance();
        const auto& entities = poolManager.GetPool<Entity>().GetAllocatedObjects();

        for (const auto& [id, system] : systems)
        {
            SystemBase* systemBase = system.get();

            if (systemBase->Enabled == false)
                continue;

            auto updateEntities = new std::vector<Entity*>();

            for (const auto& e : entities)
            {
                Entity* entity = static_cast<Entity*>(e);
                bool pass = true;

                for (const auto& requiredID : systemBase->GetRequiredComponents())
                {
                    if (entity->ContainsComponent(requiredID) == false)
                    {
                        pass = false;
                        break;
                    }
                }

                if(pass)
                {
                    updateEntities->push_back(entity);
                }
            }            

            if(updateEntities->size() != 0)
                systemBase->OnUpdate(*updateEntities);
        }
    }
}