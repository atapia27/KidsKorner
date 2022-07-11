#ifndef ALIENHEALTH_H
#define ALIENHEALTH_H

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

class AlienHealth: public QGraphicsPixmapItem{
public:
    AlienHealth (QGraphicsPixmapItem * parent = 0);
    void decrease();
    int getHealth();
    int health;

private:

};

#endif // ALIENHEALTH_H
