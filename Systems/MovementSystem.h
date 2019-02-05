#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include <anax/System.hpp>
#include "Components/VelocityComponent.h"
#include "Components/Positioncomponent.h"

struct MovementSystem : anax::System<anax::Requires<PositionComponent, VelocityComponent>>
{
    void update(double deltaTime);
};

#endif // MOVEMENTSYSTEM_H
