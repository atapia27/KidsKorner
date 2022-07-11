#include "Bullet.h"
#include "AlienEnemy.h"
#include "AlienEnemy2.h"
#include "AlienGame.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern AlienGame * alienGame; //there is an external global object calle "game"

Bullet::Bullet()
{
    //draw graphics
    //i used 50 becayse I want it to come out of  the middle of the object we are shooting it from
    setPixmap(QPixmap(":/laser.png"));
    //connect
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);   //sets the timeout to 50 ms, every bullet moves independantly after 50 ms


}

void Bullet::move(){

    //bullet collision detection
    //get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_Items = collidingItems();
    for (int i = 0, n = colliding_Items.size(); i<n; i++){
        if (typeid(*(colliding_Items[i])) == typeid(AlienEnemy) || typeid(*(colliding_Items[i])) == typeid(AlienEnemy2)){
            //increase the score
            alienGame->spacescore->increase();

            //remove them fromt he scene
            scene()->removeItem(colliding_Items[i]);
            scene()->removeItem(this);

            //delete them from the heap to save memory
             delete this;
            delete colliding_Items[i];

            //return (all code below refers to a non exsistent bullet)
            return;
        }
    }

    //bullet moves up constantly because of the timeout
    setPos(x(),y()-25);
    if(pos().y()< 0){
        scene()->removeItem(this);              //the top of the screen is 0, if it goes past 0 (if < 0), then we want to delete it
        delete this;
    }
}
