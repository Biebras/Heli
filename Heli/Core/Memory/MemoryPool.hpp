#pragma once

#include <cstddef>

namespace Heli
{
    /// @brief By having this class, we can store all the memory pools in a single container
    class MemoryPoolBase
    {
        public:
            virtual ~MemoryPoolBase() = default;
            virtual void Free(void*& object) = 0;
    };

    /// @brief A memory pool for a specific type. Allows for fast allocation and deallocation
    /// @tparam T 
    template<typename T>
    class MemoryPool : public MemoryPoolBase
    {
        public:
            MemoryPool(std::size_t size);
            ~MemoryPool();
            T* Allocate();
            void Free(T*& object);
            void Free(void*& object) override
            {
                Free(reinterpret_cast<T*&>(object));
            }

        private:
            T* memory;
            std::size_t size;

            // List of free memory addresses
            T** freeList;
            size_t availableObjects;
    };


    /// @brief Constructs the memory pool and initializes the free list
    /// @tparam T 
    /// @param size The size of the pool
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

        availableObjects = size;
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
        if (availableObjects == 0)
            return nullptr;

        // Get a free object from the free list
        availableObjects--;
        T* object = freeList[availableObjects];

        // Construct the object
        new (object) T();
        object->TypeId = GetTypeId<T>();

        return object;
    }

    template<typename T>
    void MemoryPool<T>::Free(T*& object)
    {
        // If the object is not in the memory pool, return
        if (object < memory || object >= memory + size)
            return;

        // Destruct the object
        object->~T();

        // Add the object to the free list
        freeList[availableObjects] = object;
        availableObjects++;

        // Set the object to nullptr
        object = nullptr;
    }
}
