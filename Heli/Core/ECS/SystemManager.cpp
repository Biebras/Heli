#include "SystemManager.hpp"
#include "Entity.hpp"

namespace Heli
{
    /// @brief Returns a vector of entities that meet the requirements of the given system.
    /// @param systemBase Pointer to the system to check against.
    /// @param entities Set of entities to check against.
    /// @return Vector of entities that meet the requirements of the given system.
    std::vector<Entity*> GetEntitiesToUpdate(SystemBase* systemBase, const std::unordered_set<void*>& entities)
    {
        std::vector<Entity*> updateEntities;

        // Iterate over all entities
        for (const auto& e : entities)
        {
            Entity* entity = static_cast<Entity*>(e);
            bool pass = true;

            // Check if the entity contains all required components
            for (const auto& requiredID : systemBase->GetRequiredComponents())
            {
                if (!entity->ContainsComponent(requiredID))
                {
                    pass = false;
                    break;
                }
            }

            // If the entity contains all required components, add it to the update list
            if(pass)
            {
                updateEntities.push_back(entity);
            }
        }

        return updateEntities;
    }

    /// @brief Updates all enabled systems in the manager.
    void SystemManager::Update()
    {
        auto& poolManager = MemoryManager::GetInstance();
        const auto& entities = poolManager.GetPool<Entity>().GetAllocatedObjects();

        // Iterate over all systems
        for (const auto& [id, system] : systems)
        {
            SystemBase* systemBase = system.get();

            // Skip disabled systems
            if (!systemBase->Enabled)
                continue;

            // Get a list of entities to update for this system
            std::vector<Entity*> updateEntities = GetEntitiesToUpdate(systemBase, entities);

            // Update the system with the list of entities
            if(!updateEntities.empty())
                systemBase->OnUpdate(updateEntities);
        }
    }
}
