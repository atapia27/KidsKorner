#ifndef ENEMY2_H
#define ENEMY2_H

#include <QMediaPlayer>
#include <QGraphicsRectItem>
#include <QObject>


class Enemy2: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT    //a macro that allows a class to handle signals and slots
public:
    Enemy2();
public slots:
    void move();
private:
    QMediaPlayer * DeathSound;
};


#endif // ENEMY2_H
