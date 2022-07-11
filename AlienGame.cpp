#include <QApplication>
#include <QFont>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QTimer>
#include <QLabel>
#include <QString>
#include "AlienGame.h"
#include "SpaceShipPlayer.h"
#include "AlienEnemy.h"
#include <QMediaPlayer>
#include <QPicture>
#include <QBrush>
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

extern QTimer * AlienTimer;
extern QMediaPlayer * AlienMusic;


AlienGame::AlienGame(QWidget * parent){

//create a scene
spacescene = new QGraphicsScene();
spacescene->setSceneRect(0,0,805,600);
setBackgroundBrush(QBrush(QImage(":/Space1.jpg")));
//assign the scene
setScene(spacescene);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //these are so that you dont scroll off the screen when you shoot
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(805,600);


//create a player to put into the scene
spaceship = new SpaceShipPlayer();
spaceship->setPos(400,550);
//make the item focusabe
spaceship->setFlag(QGraphicsItem::ItemIsFocusable);
spaceship->setFocus();
//add item to the scene
spacescene->addItem(spaceship);

//create a score
spacescore = new SpaceShipScore();
spacescene->addItem(spacescore);
//create health
spacehealth = new AlienHealth();
spacehealth->setPos(spacehealth->x()+5,spacehealth->y()+25);
spacescene->addItem(spacehealth);

//spawn enemies
//I wanna add two types of enemies. I will make it a random chance to get harder enemies 1/3 inside of "spawn"
AlienTimer =  new QTimer();
QObject::connect(AlienTimer, SIGNAL(timeout()),spaceship,SLOT(spawn()));
AlienTimer->start(600);  //the rate (in ms) for how fast the monsters will come out


//play background music
AlienMusic = new QMediaPlayer();
AlienMusic->setMedia(QUrl("qrc:/Lofi.mp3"));
AlienMusic->play();

}
