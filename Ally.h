#ifndef ALLY_H
#define ALLY_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>

class Ally: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT    //a macro that allows a class to handle signals and slots
public:
    Ally();
public slots:
    void move();
private:
    QMediaPlayer * upgrade;
};


#endif // ALLY_H
