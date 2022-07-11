
#ifndef SPACESHIPSCORE_H
#define SPACESHIPSCORE_H

#include <QGraphicsTextItem>

class SpaceShipScore: public QGraphicsTextItem{
public:
    SpaceShipScore (QGraphicsItem * parent = 0);
    void increase();
    int getScore();
private:
    int score;
};

#endif // SPACESCORE_H
