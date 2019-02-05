#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <anax/Component.hpp>
#include <QGraphicsPathItem>

struct SpriteComponent : anax::Component
{
    QGraphicsPathItem item;
};

#endif // SPRITECOMPONENT_H
