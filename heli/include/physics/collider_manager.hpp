#ifndef COLLISION_MANAGER_HPP
#define COLLISION_MANAGER_HPP

#include <vector>

class Collider;

void AddCollider(Collider* collider);
std::vector<Collider*> GetColliders();

#endif


