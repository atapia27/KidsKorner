#include "Player.h"
#include "Ally.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Enemy5.h"
#include "Score.h"
#include "Game.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPixmap>
#include <QObject>

extern Game * game;

Player::Player(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/Player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
        //my frame was 805x720



        /*information about the event is stored within the object.
        we can check what kind of input there is by checking "event"
        */
        if(event->key() == Qt::Key_Up){
            if(pos().y() > 200)          //in case it tries to go outside the left side of the screen
                setPos(x(), y()-135);
                }

        else if(event->key() == Qt::Key_Down){
           if(pos().y() < 450)          //in case it tries to go outside the left side of the screen
                setPos(x(), y()+135);
        }


}

void Player::spawn()
{
    int random = rand() %120;
    game->score->increase();

    if (random < 20){
        Enemy * enemy =  new Enemy();
        scene()->addItem(enemy);
    }
    else if (random < 40 && random > 20){
        Enemy2 * enemy2 = new Enemy2();
        scene()->addItem(enemy2);
    }
    else if (random < 60 && random > 40){
        Enemy3 * enemy3 = new Enemy3();
        scene()->addItem(enemy3);
    }
    else if (random < 80 && random > 60){
        Enemy4 * enemy4 = new Enemy4();
        scene()->addItem(enemy4);
    }
    else if (random < 100 && random > 80){
        Enemy5 * enemy5 = new Enemy5();
        scene()->addItem(enemy5);
    }
    else if (random < 120 && random > 100){
        Ally * ally = new Ally();
        scene()->addItem(ally);
    }

}
