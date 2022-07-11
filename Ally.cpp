#include <Ally.h>
#include <Player.h>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include "Game.h"

extern Game * game;

Ally::Ally()
{
    //we use 0 for the y because that's the top
    //position should be: 200, 335, 470

    int random = rand() % 100;

    if (random < 33)
    {
        setPos(1100, 200);
    }
    else if(random > 67)
    {
        setPos(1100, 470);
    }
    else
    {
        setPos(1100, 335);
    }

    //draw the Ally
    setPixmap(QPixmap(":/Ally.png"));


    //connect
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);   //the timer represents the time between signals. It'll do 'move()' every 50 ms

    upgrade = new QMediaPlayer();
    upgrade->setMedia(QUrl("qrc:/powerup.wav"));
}

void Ally::move()
{
    int xMovement = -35;

    setPos(x()+xMovement,y());
//    if(pos().x() + 50 > 0)
//        setPos(x()-25, y());
    QList<QGraphicsItem *> colliding_Items = collidingItems();
    for (int i = 0, n = colliding_Items.size(); i<n; i++){
        if (typeid(*(colliding_Items[i])) == typeid(Player)){
            //increase health
            game->health->increase();

            if(upgrade->state() == QMediaPlayer::PlayingState)
                upgrade->setPosition(0);

            else if(upgrade->state()==QMediaPlayer::StoppedState)
                upgrade->play();

            //remove them fromt he scene
            scene()->removeItem(this);
            //delete them from the heap to save memory
            delete this;
            //return (all code below refers to a non exsistent bullet)
            return;
        }
        //some cars are as wide as 100px, so we wanna make sure they leave the screen completeley
        if(pos().x()< -100){
           scene()->removeItem(this);
           delete this;
            }
}


}
