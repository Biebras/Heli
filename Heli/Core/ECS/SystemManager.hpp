#pragma once

#include "System.hpp"
#include "../Memory/MemoryManager.hpp"
#include "../Memory/MemoryPool.hpp"

namespace Heli
{
    class SystemManager
    {
        public:
            // Singleton
            static SystemManager& GetInstance()
            {
                static SystemManager instance;
                return instance;
            }

            template<typename T>
            void AllocateSystem();
            void Update();

        private:
            // Singleton stuff
            SystemManager() = default;
            ~SystemManager() = default;
            SystemManager(const SystemManager&) = delete;
            SystemManager& operator=(const SystemManager&) = delete;

            std::vector<std::unique_ptr<SystemBase>> systems;
            std::unordered_set<TypeId> allocatedSystemTypes;
    };

    template<typename T>
    void SystemManager::AllocateSystem() // Has some bugs when passing type that is not derived from SystemBase
    {
        // Check if the system is derived from SystemBase
        if (!std::is_base_of<SystemBase, T>::value)
        {
            LOG_ERROR("SystemManager::AllocateSystem: System is not derived from SystemBase!");
            return;
        }

        TypeId systemTypeId = GetTypeId<T>();

        // Check if a system of this type has already been allocated
        if (!allocatedSystemTypes.insert(systemTypeId).second)
        {
            LOG_WARNING("SystemManager::AllocateSystem: A system of this type has already been allocated!");
            return;
        }

        std::unique_ptr<T> system = std::make_unique<T>();
        // Assign type ID
        system->TypeID = systemTypeId;

        // Store the system in the systems vector
        systems.push_back(std::move(system));
    }
}




