#pragma once

#include <cstddef>
#include <unordered_set>

namespace Heli
{
    /// @brief Base class for memory pools.
    /// Allows for storing all memory pools in a single container.
    class MemoryPoolBase
    {
        public:
            virtual ~MemoryPoolBase() = default;
            virtual void Free(void*& object) = 0;
    };

    /// @brief A memory pool for a specific type.
    /// Allows for fast allocation and deallocation of objects of type T.
    /// @tparam T The type of objects stored in the memory pool.
    template<typename T>
    class MemoryPool : public MemoryPoolBase
    {
        public:
            MemoryPool(std::size_t size);
            ~MemoryPool();
            T* Allocate();
            void Free(T*& object);
            // Inherited via MemoryPoolBase and redirected to the correct Free function
            void Free(void*& object) override
            {
                Free(reinterpret_cast<T*&>(object));
            }
            // Function to retrieve the set of allocated blocks
            const std::unordered_set<T*>& GetAllocatedBlocks() const { return allocatedBlocks; }

        private:
            T* memory;
            std::size_t size;

            // List of free memory addresses
            T** freeList;
            size_t availableObjects;

            // Set of allocated blocks
            std::unordered_set<T*> allocatedBlocks;
    };


    /// @brief Constructs the memory pool and initializes the free list
    /// @tparam T The type of objects stored in the memory pool.
    /// @param size The size of the pool (number of objects).
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

    /// @brief Allocates an object from the pool.
    /// Constructs a new object using placement new and returns a pointer to it.
    /// If there are no available objects in the pool, returns nullptr.
    /// @return A pointer to the newly allocated object, or nullptr if the pool is full.
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
        object->TypeID = GetTypeId<T>();

        // Add the object to the set of allocated blocks
        allocatedBlocks.insert(object);

        return object;
    }

    /// @brief Frees an object and returns it to the pool.
    /// Calls the destructor on the object and adds it to the free list.
    /// If the object is not within the memory managed by the pool, does nothing.
    /// Sets the object pointer to nullptr after freeing it.
    /// @param[in,out] object A reference to a pointer to the object to be freed.
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

        // Remove the object from the set of allocated blocks
        allocatedBlocks.erase(object);

        // Set the object to nullptr
        object = nullptr;
    }
}
