#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "Game.h"
#include "GameLoop.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene(-200, -200, 400, 400);

    QGraphicsView view(&scene);
    view.show();

    Game game(&scene);
    GameLoop gl(&game, &scene);

    return a.exec();
}
