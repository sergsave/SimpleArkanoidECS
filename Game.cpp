#include "Game.h"

#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QPen>
#include <QPainterPath>

#include <Components/SpriteComponent.h>
#include <Components/Positioncomponent.h>
#include <Components/VelocityComponent.h>

namespace {

void fillPlatformSprite(QGraphicsPathItem& item)
{

    item.setPen(QPen(Qt::blue));
    item.setBrush(QBrush(Qt::blue));

    QPainterPath path;
    path.addRect(0, 0, 70, 20);
    item.setPath(path);
}

void fillBallSprite(QGraphicsPathItem& item)
{
    item.setPen(QPen(Qt::red));
    item.setBrush(QBrush(Qt::red));

    QPainterPath path;
    path.addEllipse(QPointF(), 10, 10);
    item.setPath(path);
}
}

Game::Game(QGraphicsScene *scene):
    m_scene(scene),
    m_spriteRenderSystem(scene)
{
    m_world.addSystem(m_collisionSystem);
    m_world.addSystem(m_inputSystem);
    m_world.addSystem(m_spriteRenderSystem);
    m_world.addSystem(m_movementSystem);

    QRectF scRect = scene->sceneRect();

    m_platform = m_world.createEntity();

    auto& platformSprite = m_platform.addComponent<SpriteComponent>().item;
    fillPlatformSprite(platformSprite);

    auto& platformPos = m_platform.addComponent<PositionComponent>().pos;
    platformPos = QPointF(0, scRect.bottom() - 30);

    auto& platformVel = m_platform.addComponent<VelocityComponent>().vel;
    platformVel = QVector2D(0.02, 0);

    m_balls = m_world.createEntities(3);

    std::size_t cnt = 0;
    for (auto& b: m_balls )
    {
        auto& sprite = b.addComponent<SpriteComponent>().item;
        fillBallSprite(sprite);

        auto& pos = b.addComponent<PositionComponent>().pos;
        pos = QPointF(cnt++ * 25, 0);

        auto& vel = b.addComponent<VelocityComponent>().vel;
        double x = static_cast<double> (std::rand() % 5 - 2) / 100;
        double y = static_cast<double> (std::rand() % 5 - 2) / 100;
        vel = QVector2D(x, y);
    }

    m_platform.activate();

    for (auto& b: m_balls )
       b.activate();
}

void Game::update(double deltaTime)
{
    m_world.refresh();

    m_movementSystem.update(deltaTime);
    m_spriteRenderSystem.render();
}

bool Game::isRunning()
{
    return true;
}
