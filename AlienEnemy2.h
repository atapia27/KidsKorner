#ifndef AlienEnemy2_H
#define AlienEnemy2_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>

class AlienEnemy2: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT    //a macro that allows a class to handle signals and slots
public:
    AlienEnemy2();
public slots:
    void move();
private:
    QMediaPlayer * DeathSound;

};

#endif // AlienEnemy2_H
