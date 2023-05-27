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
            template<typename T>
            void RemoveSystem();
            void Update();

        private:
            // Singleton stuff
            SystemManager() = default;
            ~SystemManager() = default;
            SystemManager(const SystemManager&) = delete;
            SystemManager& operator=(const SystemManager&) = delete;

            std::unordered_map<TypeId, std::unique_ptr<SystemBase>> systems;
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
        SystemBase* systemBase = systems[systemTypeId].get();

        if(systemBase != nullptr && systemBase->Enabled == true)
        {
            LOG_WARNING("SystemManager::AllocateSystem: System already exists!");
            return;
        }

        if (systemBase == nullptr)
        {
            std::unique_ptr<T> system = std::make_unique<T>();
            // Assign type ID
            system->TypeID = systemTypeId;
            // Enable the system
            system->Enabled = true;

            // Store the system
            systems[systemTypeId] = std::move(system);
        }
        else
        {
            systemBase->Enabled = true;
        }
    }

    template<typename T>
    void SystemManager::RemoveSystem()
    {
        TypeId systemTypeId = GetTypeId<T>();
        SystemBase* systemBase = systems[systemTypeId].get();

        if (systemBase == nullptr)
        {
            LOG_WARNING("SystemManager::RemoveSystem: System does not exist!");
            return;
        }

        systemBase->Enabled = false;
    }
}




