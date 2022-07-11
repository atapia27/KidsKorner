#include "SpaceShipPlayer.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "AlienEnemy.h"
#include "AlienEnemy2.h"
#include "AlienGame.h"
#include <QKeyEvent>

//we play music this way
SpaceShipPlayer::SpaceShipPlayer(QGraphicsItem *parent)
{
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/LaserGun3.mp3"));
    setPixmap(QPixmap(":/ship.png"));

}

void SpaceShipPlayer::keyPressEvent(QKeyEvent *event){

    /*
    information about the event is stored within the object.
    we can check what kind of input there is by checking "event"
    */


    if(event->key() == Qt::Key_Left){
        if(pos().x() > 25)          //in case it tries to go outside the left side of the screen
            setPos(x()-25, y());
            }

    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 50 < 800)          //in case it tries to go outside the right side of the screen
            setPos(x()+25, y());
    }

    //create a bullet
    //we create this in the player class so that the bullets spawn relative to the player
    if(event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        bullet->setPos(x(),y()-50);
        scene()->addItem(bullet);     //now we have to add it to a scene so that it shows up


    //play bullet sound
        if(bulletSound->state() == QMediaPlayer::PlayingState)
            bulletSound->setPosition(0);

        else if(bulletSound->state()==QMediaPlayer::StoppedState)
            bulletSound->play();
    }
}

    //create enemies
void SpaceShipPlayer::spawn()
{
    int chance = rand() % 100;

    if (chance < 67)
    {
        AlienEnemy * alienEnemy =  new AlienEnemy();
        scene()->addItem(alienEnemy);
    }

    else
    {
        AlienEnemy2 * alienEnemy2 = new AlienEnemy2();
        scene()->addItem(alienEnemy2);
    }

}
