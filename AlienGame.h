#ifndef ALIENGAME_H
#define ALIENGAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "SpaceShipPlayer.h"
#include "SpaceShipScore.h"
#include "AlienHealth.h"


class AlienGame: public QGraphicsView{
public:
    AlienGame(QWidget * parent = 0);

    //we use all of these variables inside of Game.cpp so that we can intialize them to new object
    QGraphicsScene * spacescene;
    SpaceShipPlayer * spaceship;
    SpaceShipScore * spacescore;
    AlienHealth * spacehealth;

};

#endif // ALIENGAME_H
