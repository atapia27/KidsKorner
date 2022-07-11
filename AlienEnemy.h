#ifndef AlienEnemy_H
#define AlienEnemy_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>

class AlienEnemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT    //a macro that allows a class to handle signals and slots
public:
    AlienEnemy();
public slots:
    void move();
private:
    QMediaPlayer * DeathSound;
};

#endif // AlienEnemy_H
