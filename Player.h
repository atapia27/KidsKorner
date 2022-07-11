#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player (QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent* event);
public slots:
    void spawn();
private:


};

#endif // PLAYER_H
