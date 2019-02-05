#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include <anax/System.hpp>
#include "Components/CollisionComponent.h"

struct CollisionSystem : anax::System<anax::Requires<CollisionComponent>>
{
//    CollisionSystem();
    void update(double deltaTime);
};

#endif // COLLISIONSYSTEM_H
