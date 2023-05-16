#include "MemoryManager.hpp"

namespace Heli
{
    MemoryManager::~MemoryManager()
    {
        for (auto& pool : pools)
        {
            pool.second.reset();
        }
    }

    /// @brief Gets the memory pool for the specified type ID.
    /// @param typeId The type ID of the objects stored in the memory pool.
    /// @return A reference to the memory pool for the specified type ID.
    MemoryPoolBase& MemoryManager::GetPool(TypeId typeId)
    {   
        // Find the pool for the given type index
        auto it = pools.find(typeId);

        // if the pool is found, return it
        if (it != pools.end())
        {
            return *(it->second.get());
        }
        else
        {
            throw std::runtime_error("No pool found for the given type");
        }
    }
}