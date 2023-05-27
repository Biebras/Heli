#include "SystemManager.hpp"
#include "Entity.hpp"

namespace Heli
{
    std::vector<Entity*> GetEntitiesToUpdate(SystemBase* systemBase, const std::unordered_set<void*>& entities)
    {
        std::vector<Entity*> updateEntities;

        for (const auto& e : entities)
        {
            Entity* entity = static_cast<Entity*>(e);
            bool pass = true;

            for (const auto& requiredID : systemBase->GetRequiredComponents())
            {
                if (!entity->ContainsComponent(requiredID))
                {
                    pass = false;
                    break;
                }
            }

            if(pass)
            {
                updateEntities.push_back(entity);
            }
        }

        return updateEntities;
    }

    void SystemManager::Update()
    {
        auto& poolManager = MemoryManager::GetInstance();
        const auto& entities = poolManager.GetPool<Entity>().GetAllocatedObjects();

        for (const auto& [id, system] : systems)
        {
            SystemBase* systemBase = system.get();

            if (!systemBase->Enabled)
                continue;

            std::vector<Entity*> updateEntities = GetEntitiesToUpdate(systemBase, entities);

            if(!updateEntities.empty())
                systemBase->OnUpdate(updateEntities);
        }
    }
}