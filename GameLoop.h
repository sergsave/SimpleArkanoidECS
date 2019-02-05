#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Game.h"
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>

class GameLoop : QObject
{
   Q_OBJECT
public:
    GameLoop(Game * game, QGraphicsScene * scene)
        : m_game(game)
    {
        m_timer.start(m_period);
        connect(&m_timer, SIGNAL(timeout()), this, SLOT(update()));
    }
private:
    static const int m_period = 10;
    Game * m_game;
    QTimer m_timer;
private slots:
    void update()
    {
        if(m_game->isRunning())
        {
            m_game->update(m_period);
        }
    }
};

#endif // GAMELOOP_H
