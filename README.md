# Heli Game Engine

Heli is a simple and lightweight 2D game engine that uses an Entity-Component-System (ECS) architecture.

## What I want Heli to be
- Simple and easy to use
- Lightweight
- 2D only
- ECS architecture
- Build in tweening library

# Using ECS in Heli

The provided code demonstrates the usage of an Entity-Component-System (ECS) architecture in the Heli engine.

## Creating Components
```cpp
struct PositionComponent : public Component 
{
    float x;
    float y;
};
```

## Creating Systems
`MovementSystem` requires that entities have `PositionComponent`
```cpp
class MovementSystem : public System<PositionComponent>
{
    public:
        virtual void OnUpdate(std::vector<Entity*> entities) override
        {
         
        }
};
```

## Initialization

First, references to the `MemoryManager` and `SystemManager` singletons are obtained. These managers are responsible for managing memory pools and systems, respectively.

```cpp
auto& poolManager = MemoryManager::GetInstance();
auto& systemManager = SystemManager::GetInstance();
```
Next, memory pools for entities and components are created using the `CreatePool` function of the `MemoryManager`. In this example, a pool for `Entity` is created.

```cpp
auto& entityPool = poolManager.CreatePool<Entity>(10);
```
After creating the memory pools, systems are allocated using the `AllocateSystem` function of the `SystemManager`. In this example, a `MovementSystem` is allocated.

```cpp
systemManager.AllocateSystem<MovementSystem>();
```

## Creating Entities
Entities are created by allocating them from the entity pool. In this example, a player entity is created.
```cpp
Entity* player = entityPool.Allocate();
```
After creating the entity, components can be added to it using the `AddComponent` function. In this example, the player entity is given a `PositionComponent`.
```cpp
player->AddComponent(positionPool.Allocate());
```

## Updating Systems
Systems are updated by calling the `Update` function of the `SystemManager`. This will update all enabled systems in the order they were allocated.
```cpp
systemManager.Update();
```
In this example, the `MovementSystem` will be updated.
# Other things

## TODO MVP
- [ ] Switch to CMake
- [X] ECS
- [ ] Graphics library/OpenGL
- [ ] Event system
- [ ] Unit testing
- [ ] Audio system
- [ ] Git Testing

## Future Improvements
- [ ] Memory Management
    - [ ] Allign Memory
    - [ ] Maybe switch to smart pointers?
    - [ ] Thread Safty
- [ ] ECS
    - [ ] Sparse set?
    - [ ] Automatic allocation
