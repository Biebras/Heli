#pragma once

#include "System.hpp"
#include "../Memory/MemoryManager.hpp"
#include "../Memory/MemoryPool.hpp"

namespace Heli
{
    /// @brief Manager class for systems in the Heli engine.
    class SystemManager
    {
        public:
            /// @brief Returns a reference to the singleton instance of the SystemManager.
            /// @return Reference to the singleton instance of the SystemManager.
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

            /// Map of systems by their type ID.
            std::unordered_map<TypeId, std::unique_ptr<SystemBase>> systems;
    };

    /// @brief Allocates a system of the given type.
    /// @tparam T Type of system to allocate.
    template<typename T>
    void SystemManager::AllocateSystem()
    {
        // Check if the system is derived from SystemBase
        if (!std::is_base_of<SystemBase, T>::value)
        {
            LOG_ERROR("SystemManager::AllocateSystem: System is not derived from SystemBase!");
            return;
        }

        TypeId systemTypeId = GetTypeId<T>();
        SystemBase* systemBase = systems[systemTypeId].get();

        // Check if the system already exists and is enabled
        if(systemBase != nullptr && systemBase->Enabled == true)
        {
            LOG_WARNING("SystemManager::AllocateSystem: System already exists!");
            return;
        }

        // If the system does not exist, create it
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
            // If the system exists but is disabled, enable it
            systemBase->Enabled = true;
        }
    }

    /// @brief Removes a system of the given type.
    /// @tparam T Type of system to remove.
    template<typename T>
    void SystemManager::RemoveSystem()
    {
        TypeId systemTypeId = GetTypeId<T>();
        SystemBase* systemBase = systems[systemTypeId].get();

        // Check if the system exists
        if (systemBase == nullptr)
        {
            LOG_WARNING("SystemManager::RemoveSystem: System does not exist!");
            return;
        }

        // Disable the system
        systemBase->Enabled = false;
    }
}
