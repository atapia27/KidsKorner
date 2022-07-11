#include "Game.h"
#include "QTimer"

extern QTimer * timer;
extern QMediaPlayer * music;
extern Score * score;

Game::Game(QWidget * parent){

    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,720);
    setBackgroundBrush(QBrush(QImage(":/Road2.png")));
    //assign the scene
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //these are so that you dont scroll off the screen when you shoot
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,720);


    //create a player to put into the scene
    player = new Player();
    player->setPos(100,335);
    //make the item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //add item to the scene
    scene->addItem(player);

    //create a score
    score = new Score();
    scene->addItem(score);
    //create health
    health = new Health();
    health->setPos(health->x()+5,health->y()+25);
    scene->addItem(health);

    //spawn enemies
    timer =  new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),player,SLOT(spawn()));

    timer->start(480);  //the rate (in ms) for how fast the monsters will come out


    //play background music
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music.mp3"));
    music->play();

}
