#ifndef SPRITERENDERINGSYSTEM_H
#define SPRITERENDERINGSYSTEM_H

#include <anax/System.hpp>
#include "Components/SpriteComponent.h"
#include "Components/Positioncomponent.h"

class QGraphicsScene;

class SpriteRenderingSystem : public anax::System<anax::Requires<SpriteComponent, PositionComponent>>
{
public:
    SpriteRenderingSystem(QGraphicsScene * scene) : m_scene(scene){}
    void render();

private:
    QGraphicsScene * m_scene;
};

#endif // SPRITERENDERINGSYSTEM_H
