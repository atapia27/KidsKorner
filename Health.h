#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "mainwindow.h"

class Health: public QGraphicsPixmapItem{
public:
    Health (QGraphicsPixmapItem * parent = 0);
    void decrease();
    void increase();
    int getHealth();
    int health;

private:


};

#endif // HEALTH_H
