#ifndef VELOCITYCOMPONENT_H
#define VELOCITYCOMPONENT_H

#include <anax/Component.hpp>
#include <QVector2D>

struct VelocityComponent : anax::Component
{
    QVector2D vel;
};

#endif // VELOCITYCOMPONENT_H
