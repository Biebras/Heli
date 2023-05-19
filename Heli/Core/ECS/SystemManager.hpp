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
            void AddSystem(T* system);
            void Update();

        private:
            // Singleton stuff
            SystemManager() : systemPool(MemoryManager::GetInstance().CreatePool<SystemBase*>(500)) {}
            ~SystemManager() = default;
            SystemManager(const SystemManager&) = delete;
            SystemManager& operator=(const SystemManager&) = delete;

            const MemoryPool<SystemBase*>& systemPool;
    };

    template<typename T>
    void AddSystem(T* system)
    {
        //SystemBase* systemBase = static_cast<SystemBase*>(system);
        //systemPool.Allocate(systemBase);
    }
}




