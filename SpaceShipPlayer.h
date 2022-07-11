#ifndef SPACESHIPPLAYER_H
#define SPACESHIPPLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>

class SpaceShipPlayer: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    SpaceShipPlayer (QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent* event);
public slots:
    void spawn();
private:
    QMediaPlayer * bulletSound;

};

#endif // SPACESHIP_H
