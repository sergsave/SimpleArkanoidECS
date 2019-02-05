#-------------------------------------------------
#
# Project created by QtCreator 2019-02-04T23:28:58
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11
TARGET = SimpleArkanoidECS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    Game.cpp \
    Systems/InputSystem.cpp \
    Systems/CollisionSystem.cpp \
    Systems/MovementSystem.cpp \
    Systems/SpriteRenderingSystem.cpp

HEADERS += \
    Game.h \
    Components/SpriteComponent.h \
    Components/VelocityComponent.h \
    Components/CollisionComponent.h \
    Systems/InputSystem.h \
    Systems/CollisionSystem.h \
    Systems/MovementSystem.h \
    GameLoop.h \
    Systems/SpriteRenderingSystem.h \
    Components/Positioncomponent.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/local/lib/release/ -lanax
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/local/lib/debug/ -lanax
else:unix: LIBS += -L$$PWD/../../../../usr/local/lib/ -lanax

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include
