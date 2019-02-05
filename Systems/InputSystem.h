#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "anax/System.hpp"
#include "Components/VelocityComponent.h"

struct InputSystem : anax::System<anax::Requires<VelocityComponent>>
{
    void update(double deltaTime);
};

#endif // INPUTSYSTEM_H
