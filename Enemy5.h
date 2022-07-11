#ifndef ENEMY5_H
#define ENEMY5_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>

class Enemy5: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT    //a macro that allows a class to handle signals and slots
public:
    Enemy5();
public slots:
    void move();
private:
    QMediaPlayer * DeathSound;
};

#endif // ENEMY5_H
