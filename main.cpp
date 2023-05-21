#include <iostream>

#include "Heli/HeliCore.hpp"

using namespace Heli;

int main()
{
    auto& poolManager = MemoryManager::GetInstance();
    auto& systemManager = SystemManager::GetInstance();

    //MemoryPool<Entity>& entityPool = poolManager.CreatePool<Entity>(10);
    MemoryPool<TransformComponent>& transformPool = poolManager.CreatePool<TransformComponent>(2);

    //Entity* entity = entityPool.Allocate();
    systemManager.AllocateSystem<TransformSystem>();
    systemManager.AllocateSystem<ShitSystem>();
    //systemManager.AllocateSystem<TransformSystem>();
    
    systemManager.Update();

    TransformComponent* transform1 = transformPool.Allocate();
    TransformComponent* transform2 = transformPool.Allocate();

    LOG("Allocated transforms count: %d", transformPool.GetAllocatedBlocks().size());

    //entity->AddComponent(transform1);

    transform1->positionX = 10;
    transform1->positionY = 20;

    transform2->positionX = 30;
    transform2->positionY = 40;

    LOG("Transform1 position: %f, %f", transform1->positionX, transform1->positionY);
    LOG("Transform2 position: %f, %f", transform2->positionX, transform2->positionY);

    transformPool.Free(transform1);

    LOG("Allocated transforms count: %d", transformPool.GetAllocatedBlocks().size());

    TransformComponent* transform3 = transformPool.Allocate();

    for (auto& transform : transformPool.GetAllocatedBlocks())
    {
        LOG("Transform position: %f, %f", transform->positionX, transform->positionY);
    }

    return 0;
}
