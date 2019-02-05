#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include <anax/Component.hpp>
#include <QPointF>

struct PositionComponent : anax::Component
{
    QPointF pos;
};

#endif // POSITIONCOMPONENT_H
