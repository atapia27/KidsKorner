#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "Player.h"
#include "Health.h"
#include "Score.h"


class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);

    //we use all of these variables inside of Game.cpp so that we can intialize them to new object
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
};

#endif // GAME_H
