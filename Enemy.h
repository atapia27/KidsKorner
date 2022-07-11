#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>


class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT    //a macro that allows a class to handle signals and slots
public:
    Enemy();
public slots:
    void move();
private:
    QMediaPlayer * DeathSound;
};

#endif // ENEMY_H
