#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT    //a macro that allows a class to handle signals and slots
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H
