#pragma once

#include <cstddef>

namespace Heli
{
    template<typename T>
    class MemoryPool
    {
    public:
        MemoryPool(std::size_t size);
        ~MemoryPool();
        T* Allocate();
        void Free(T* object);

    private:
        T* memory;
        std::size_t size;

        // List of free memory addresses
        T** freeList;
        size_t availableSize;
    };

    template<typename T>
    MemoryPool<T>::MemoryPool(std::size_t size)
    {
        // Allocate memory
        memory = new T[size];
        this->size = size;

        // Initialize the free list
        freeList = new T * [size];

        for (size_t i = 0; i < size; i++)
        {
            freeList[i] = &memory[i];
        }

        availableSize = size;
    }

    template<typename T>
    MemoryPool<T>::~MemoryPool()
    {
        // Free the memory
        delete[] memory;
        delete[] freeList;
    }

    template<typename T>
    T* MemoryPool<T>::Allocate()
    {
        // If there is no more available memory, return nullptr
        if (availableSize == 0)
            return nullptr;

        // Get a free object from the free list
        availableSize--;
        T* object = freeList[availableSize];

        // Construct the object
        new (object) T();

        return object;
    }

    template<typename T>
    void MemoryPool<T>::Free(T* object)
    {
        if (availableSize == size)
            return;

        // If the object is not in the memory pool, return
        if (object < memory || object >= memory + size)
            return;

        // Destruct the object
        object->~T();

        // Add the object to the free list
        freeList[availableSize++] = object;
    }
}
