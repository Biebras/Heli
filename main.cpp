#include <iostream>

#include "Heli/HeliCore.hpp"

using namespace Heli;

int main()
{
    auto& poolManager = MemoryManager::GetInstance();

    poolManager.CreatePool<Entity>(10);
    poolManager.CreatePool<TransformComponent>(2);
    //poolManager.CreatePool<VelocityComponent>(10);

    MemoryPool<Entity>& entityPool = poolManager.GetPool<Entity>();
    MemoryPool<TransformComponent>& transformPool = poolManager.GetPool<TransformComponent>();

    //Entity* entity = entityPool.Allocate();

    TransformComponent* transform1 = transformPool.Allocate();
    TransformComponent* transform2 = transformPool.Allocate();

    //entity->AddComponent(transform1);

    transform1->positionX = 10;
    transform1->positionY = 20;

    transform2->positionX = 30;
    transform2->positionY = 40;

    LOG("Transform1 position: %f, %f", transform1->positionX, transform1->positionY);
    LOG("Transform2 position: %f, %f", transform2->positionX, transform2->positionY);

    transformPool.Free(transform1);
    TransformComponent* transform3 = transformPool.Allocate();

    LOG("Transform3 position: %f, %f", transform3->positionX, transform3->positionY);

    //entityPool.Free(entity);
    //transformPool.Free(transform1);
    
    //transform1->positionX = 40;
    //transform1->positionY = 50;

    //LogManager::Log("Transform1 position: %f, %f", transform1->positionX, transform1->positionY);

    //entity->AddComponent(transform1);
    //entity->AddComponent(transform2);
    //entity->AddComponent(velocity);

    //entityPool.Free(entity);
    //transformPool.Free(transform2);

    //LogManager::Log("Entity ptr: %p", entity);
    //LogManager::Log("Velocity ptr: %p", velocity);
    //LogManager::Log("Transform1 ptr: %p", transform1);
    //LogManager::Log("Transform2 ptr: %p", transform2);

    // The segmentation error is probably caused because when we exit we want to manually call free memory management

    return 0;
}
