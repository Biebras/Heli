#pragma once

#include <vector>
#include <typeindex>
#include <unordered_map>

#include "MemoryPool.hpp"
#include "../ECS/Component.hpp"
#include "../Logger/Debug.hpp"
#include "../ECS/ClassTypeId.hpp"

namespace Heli
{
    /// @brief Manages all the memory pools. 
    /// Stores them in a hashmap and provides functions to get and create pools
    class MemoryManager
    {
        public:
            // Singleton
            static MemoryManager& GetInstance()
            {
                static MemoryManager instance;
                return instance;
            }

            template <typename T>
            MemoryPool<T>& GetPool();
            MemoryPoolBase& GetPool(TypeId typeId);
            template <typename T>
            MemoryPool<T>& CreatePool(std::size_t size);
            void DeallocateComponent(Component* component);

        private:
            // Singleton stuff
            MemoryManager() = default;
            ~MemoryManager();
            MemoryManager(const MemoryManager&) = delete;
            MemoryManager& operator=(const MemoryManager&) = delete;

            std::unordered_map<TypeId, std::unique_ptr<MemoryPoolBase>> pools;
    };

    /// @brief Finds the pool in the pool hashmap and returns it
    /// @tparam T 
    /// @return MemoryPool<T>&
    template <typename T>
    MemoryPool<T>& MemoryManager::GetPool()
    {
        // Find the pool for the given type
        TypeId typeId = GetTypeId<T>();
        auto& pool = pools[typeId];

        // Cast the pool to the correct type
        return static_cast<MemoryPool<T>&>(*pool);
    }

    /// @brief Creates a pool for the given type and adds it to the pool hashmap
    /// @tparam T
    /// @param size The size of the pool 
    template <typename T>
    MemoryPool<T>& MemoryManager::CreatePool(std::size_t size)
    {
        TypeId typeId = GetTypeId<T>();
        auto pool = std::make_unique<MemoryPool<T>>(size);
        pools[typeId] = std::move(pool);
        return static_cast<MemoryPool<T>&>(*pools[typeId]);
    }
}
