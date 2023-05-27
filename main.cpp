#include <iostream>

#include "Heli/HeliCore.hpp"

using namespace Heli;

int main()
{
    auto& poolManager = MemoryManager::GetInstance();
    auto& systemManager = SystemManager::GetInstance();

    auto& transformPool = poolManager.CreatePool<TransformComponent>(10);
    auto& velocityPool = poolManager.CreatePool<VelocityComponent>(10);
    auto& entityPool = poolManager.CreatePool<Entity>(10);

    Entity* player = entityPool.Allocate();
    Entity* enemy1 = entityPool.Allocate();
    Entity* enemy2 = entityPool.Allocate();

    player->AddComponent(transformPool.Allocate());

    enemy1->AddComponent(transformPool.Allocate());
    enemy1->AddComponent(velocityPool.Allocate());

    enemy2->AddComponent(transformPool.Allocate());
    enemy2->AddComponent(velocityPool.Allocate());

    systemManager.AllocateSystem<ShitSystem>();
    systemManager.AllocateSystem<TransformSystem>();

    systemManager.Update();

    return 0;
}
