#include "SystemManager.hpp"
#include "Entity.hpp"

namespace Heli
{
    /// @brief Returns a vector of entities that meet the requirements of the given system.
    /// @param systemBase Pointer to the system to check against.
    /// @param entities Set of entities to check against.
    /// @return Unordered set of entities that meet the requirements of the given system.
    std::unordered_set<Entity*> GetEntitiesToUpdate(SystemBase* systemBase)
    {
        std::unordered_set<Entity*> entities;

        for (const auto& componentID : systemBase->GetRequiredComponents())
        {
            const auto& pool = MemoryManager::GetInstance().GetPool(componentID);
            const auto& allocatedObjects = pool.GetAllocatedObjects();

            for (const auto& object : allocatedObjects)
            {
                Component* component = static_cast<Component*>(object);
                entities.insert(static_cast<Entity*>(component->ParentEntity));
            }
        }
        
        return entities;
    }

    /// @brief Updates all enabled systems in the manager.
    void SystemManager::Update()
    {
        // Iterate over all systems
        for (const auto& [id, system] : systems)
        {
            SystemBase* systemBase = system.get();

            // Skip disabled systems
            if (!systemBase->Enabled)
                continue;

            systemBase->OnUpdate(GetEntitiesToUpdate(systemBase));
        }
    }
}
