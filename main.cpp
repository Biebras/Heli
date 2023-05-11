#include <iostream>

#include "Entity.hpp"
#include "MovementSystem.hpp"
#include "TransformComponent.hpp"
#include "MemoryPool.hpp"
#include "PoolManager.hpp"

using namespace Heli;

int main()
{
    auto& poolManager = PoolManager::GetInstance();

    poolManager.CreatePool<Entity>(10);
    poolManager.CreatePool<TransformComponent>(10);

    MemoryPool<Entity>& entityPool = poolManager.GetPool<Entity>();
    MemoryPool<TransformComponent>& transformPool = poolManager.GetPool<TransformComponent>();

    Entity* entity = entityPool.Allocate();
    TransformComponent* transform = transformPool.Allocate();

    printf("Entity: %p\n", entity);
    printf("Transform: %p\n", transform);

    entityPool.Free(entity);
    transformPool.Free(transform);

    printf("Entity: %p\n", entity);
    printf("Transform: %p\n", transform);

    return 0;
}
