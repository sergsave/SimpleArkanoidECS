#include "MovementSystem.h"
#include <QVector2D>

void MovementSystem::update(double deltaTime)
{
    auto entities = getEntities();
    for(auto& entity : entities)
    {
        auto& position = entity.getComponent<PositionComponent>().pos;
        auto& velocity = entity.getComponent<VelocityComponent>().vel;

        auto deltaPos = (velocity * deltaTime).toPointF();
        position = position + deltaPos;
    }
}
