#include <iostream>

#include "Heli/HeliCore.hpp"

using namespace Heli;

int main() 
{
    // Get references to the pool manager and system manager
    auto& poolManager = MemoryManager::GetInstance();
    auto& systemManager = SystemManager::GetInstance();

    // Create pools for entities and components
    auto& entityPool = poolManager.CreatePool<Entity>(10);
    auto& positionPool = poolManager.CreatePool<PositionComponent>(10);
    auto& spritePool = poolManager.CreatePool<SpriteComponent>(10);

    // Allocate systems
    systemManager.AllocateSystem<MovementSystem>();
    systemManager.AllocateSystem<RenderingSystem>();

    // Create player entity and add components
    Entity* player = entityPool.Allocate();
    player->AddComponent(positionPool.Allocate());
    player->AddComponent(spritePool.Allocate());

    // Create enemy entity and add components
    Entity* enemy = entityPool.Allocate();
    enemy->AddComponent(positionPool.Allocate());
    enemy->AddComponent(spritePool.Allocate());

    // Update systems
    systemManager.Update();

    return 0;
}

