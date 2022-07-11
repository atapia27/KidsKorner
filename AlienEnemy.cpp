#include "AlienEnemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "AlienGame.h"


extern AlienGame * alienGame;

//main in the main.cpp file calls a constructor of AlienEnemy, which in turn calls the "move" AlienEnemy function
//it starts the spawning of the enemies
AlienEnemy::AlienEnemy()
{
    //set random position
    //we use %700 because since our enemies are 100 units wide, and the screen is 800 wide, we don't want them to spawn off screen
    int random_number = rand() % 750;

    //we use 0 for the y because that's the top
    setPos(random_number, 0);


    //draw the AlienEnemy
    setPixmap(QPixmap(":/Alien.png"));


    //connect
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);   //the timer represents the time between signals. It'll do 'move()' every 50 ms


    DeathSound = new QMediaPlayer();
    DeathSound->setMedia(QUrl("qrc:/Death.mp3"));

}

void AlienEnemy::move(){
    //we want the enemies to move down and to move slowly
    /////////////////////////////////////////////////////////
    //GAME DESIGN IDEA: when the speed goes past 8 we can add angry/fast movement animations of the enemies
    /////////////////////////////////////////////////////////

    //this is going to be the horizontal distance that the AlienEnemy will shift randomly
    int xMovement = rand() % 5;
    int polarity = rand() % 10;
    if (polarity > 4){
        xMovement = -xMovement;     //i'm gonna shift their X-movement, the direction of the X-movement will be random and predicted by polarity
    }
    int yMovement = rand() % 5;
    setPos(x()+xMovement,y()+yMovement);


    if(pos().x() + 50 < 800)          //in case it tries to go outside the right side of the screen
        setPos(x()+25, y());
    if(pos().x() > 25)          //in case it tries to go outside the left side of the screen
        setPos(x()-25, y());



    if(pos().y()> 600){
        //decrease health
        if(alienGame->spacehealth->getHealth() > 0)
        {
            alienGame->spacehealth->decrease();

            //play DeathSound sound
                if(DeathSound->state() == QMediaPlayer::PlayingState)
                    DeathSound->setPosition(0);

                else if(DeathSound->state()==QMediaPlayer::StoppedState)
                    DeathSound->play();
        }


            scene()->removeItem(this);              //the top of the screen is 0, if it goes past 0 (if < 0), then we want to delete it
            delete this;
        }


}
