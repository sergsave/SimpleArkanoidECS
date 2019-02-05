#ifndef GAME_H
#define GAME_H

#include <vector>

#include <anax/anax.hpp>

#include "Systems/CollisionSystem.h"
#include "Systems/InputSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/SpriteRenderingSystem.h"

class QGraphicsScene;

class Game
{
public:
    Game(QGraphicsScene * scene);

    void update (double deltaTime);
    bool isRunning();
private:
    QGraphicsScene * m_scene;

    CollisionSystem m_collisionSystem;
    InputSystem m_inputSystem;
    MovementSystem m_movementSystem;
    SpriteRenderingSystem m_spriteRenderSystem;

    anax::World m_world;
    anax::Entity m_platform;
    anax::Entity m_deadZone;
    std::vector<anax::Entity> m_walls;
    std::vector<anax::Entity> m_balls;
};


#endif // GAME_H
