#include <iostream>

#include "Entity.hpp"
#include "MovementSystem.hpp"
#include "TransformComponent.hpp"
#include "MemoryPool.hpp"

using namespace Heli;

int main()
{
    MemoryPool<int> pool(3);

    // Allocate an int object from the pool
    int* x = pool.Allocate();
    *x = 42;

    // Allocate an int object from the pool
    int* y = pool.Allocate();
    *y = 42;

    // Allocate an int object from the pool
    int z = *pool.Allocate();
    z = 42;

    std::cout << *x << std::endl;

    pool.Free(x);

    // Allocate an int object from the pool
    int* h = pool.Allocate();
    *h = 42;

    // Use the int object

    std::cout << *y << std::endl;
    std::cout << z << std::endl;
    std::cout << *h << std::endl;

    // Free the int object
    pool.Free(x);

    return 0;
}
