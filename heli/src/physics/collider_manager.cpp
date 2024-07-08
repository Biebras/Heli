#include <physics/collider_manager.hpp>

std::vector<Collider*> colliders;

void AddCollider(Collider *collision)
{
    colliders.push_back(collision);
}

std::vector<Collider*> GetColliders()
{
    return colliders;
}
