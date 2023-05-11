#pragma once

#include <vector>
#include <typeindex>
#include <unordered_map>

#include "MemoryPool.hpp"

namespace Heli
{
    /// @brief Manages all the memory pools. 
    /// Stores them in a hashmap and provides functions to get and create pools
    class PoolManager
    {
        public:
            // Singleton
            static PoolManager& GetInstance()
            {
                static PoolManager instance;
                return instance;
            }

            template <typename T>
            MemoryPool<T>& GetPool();

            template <typename T>
            void CreatePool(std::size_t size);

        private:
            // Singleton stuff
            PoolManager() = default;
            ~PoolManager() = default;
            PoolManager(const PoolManager&) = delete;
            PoolManager& operator=(const PoolManager&) = delete;

            std::unordered_map<std::type_index, std::unique_ptr<MemoryPoolBase>> pools;
    };

    /// @brief Finds the pool in the pool hashmap and returns it
    /// @tparam T 
    /// @return MemoryPool<T>&
    template <typename T>
    MemoryPool<T>& PoolManager::GetPool()
    {
        // Find the pool for the given type
        auto it = pools.find(std::type_index(typeid(T)));

        // if the pool is found, return it
        if (it != pools.end())
        {
            // Cast the pool to the correct type
            return *static_cast<MemoryPool<T>*>(it->second.get());
        }
        else
        {
            throw std::runtime_error("No pool found for the given type");
        }
    }

    /// @brief Creates a pool for the given type and adds it to the pool hashmap
    /// @tparam T
    /// @param size The size of the pool 
    template <typename T>
    void PoolManager::CreatePool(std::size_t size)
    {
        auto pool = std::make_unique<MemoryPool<T>>(size);
        pools[std::type_index(typeid(T))] = std::move(pool);
    }
}
