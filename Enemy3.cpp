#include <Enemy3.h>
#include <Player.h>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include "Game.h"

extern Game * game;

Enemy3::Enemy3()
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

    //draw the enemy
    setPixmap(QPixmap(":/Enemy3.png"));


    //connect
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);   //the timer represents the time between signals. It'll do 'move()' every 50 ms

    DeathSound = new QMediaPlayer();
    DeathSound->setMedia(QUrl("qrc:/sounds/Death.mp3"));
}

void Enemy3::move()
{
    int xMovement = -35;

    setPos(x()+xMovement,y());

    QList<QGraphicsItem *> colliding_Items = collidingItems();
    for (int i = 0, n = colliding_Items.size(); i<n; i++){
        if (typeid(*(colliding_Items[i])) == typeid(Player)){
            //decrease health
            if(game->health->getHealth() > 0)
            {
                game->health->decrease();

                //play DeathSound sound
                    if(DeathSound->state() == QMediaPlayer::PlayingState)
                        DeathSound->setPosition(0);

                    else if(DeathSound->state()==QMediaPlayer::StoppedState)
                        DeathSound->play();

            }


            //remove them fromt he scene
            scene()->removeItem(this);
            //delete them from the heap to save memory
            delete this;
            return;
        }

        //some cars are as wide as 100px, so we wanna make sure they leave the screen completeley
        if(pos().x() < 0){
            //increase score
            game->score->increase();
           scene()->removeItem(this);
           delete this;
            }
}


}
