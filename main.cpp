#include <iostream>

#include "Entity.hpp"
#include "MovementSystem.hpp"
#include "TransformComponent.hpp"
#include "MemoryPool.hpp"
#include "PoolManager.hpp"
#include "LogManager.hpp"
#include "ClassTypeId.hpp"
#include "ClassTypeId.hpp"
#include "VelocityComponent.hpp"

using namespace Heli;

int main()
{
    auto& poolManager = PoolManager::GetInstance();

    poolManager.CreatePool<Entity>(10);
    poolManager.CreatePool<TransformComponent>(10);
    poolManager.CreatePool<VelocityComponent>(10);

    MemoryPool<Entity>& entityPool = poolManager.GetPool<Entity>();
    MemoryPool<TransformComponent>& transformPool = poolManager.GetPool<TransformComponent>();
    MemoryPool<VelocityComponent>& velocityPool = poolManager.GetPool<VelocityComponent>();

    Entity* entity = entityPool.Allocate();
    VelocityComponent* velocity = velocityPool.Allocate();
    TransformComponent* transform1 = transformPool.Allocate();
    TransformComponent* transform2 = transformPool.Allocate();

    entity->AddComponent(transform1);
    entity->AddComponent(transform2);
    entity->AddComponent(velocity);

    entityPool.Free(entity);
    transformPool.Free(transform2);

    LogManager::Log("Entity ptr: %p", entity);
    LogManager::Log("Velocity ptr: %p", velocity);
    LogManager::Log("Transform1 ptr: %p", transform1);
    LogManager::Log("Transform2 ptr: %p", transform2);

    return 0;
}
