#ifndef ENEMY4_H
#define ENEMY4_H

#include <QMediaPlayer>
#include <QGraphicsRectItem>
#include <QObject>

class Enemy4: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT    //a macro that allows a class to handle signals and slots
public:
    Enemy4();
public slots:
    void move();
private:
    QMediaPlayer * DeathSound;
};


#endif // ENEMY4_H
