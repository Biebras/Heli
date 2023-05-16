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