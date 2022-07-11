#ifndef ENEMY3_H
#define ENEMY3_H

#include <QMediaPlayer>
#include <QGraphicsRectItem>
#include <QObject>

class Enemy3: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT    //a macro that allows a class to handle signals and slots
public:
    Enemy3();
public slots:
    void move();
private:
    QMediaPlayer * DeathSound;
};


#endif // ENEMY3_H
