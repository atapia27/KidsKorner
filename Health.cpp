#include "Health.h"
#include "mainwindow.h"
#include "QGraphicsTextItem"
#include <QFont>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include "Game.h"
#include <QPalette>
#include "QTimer"
#include <QWidgetAction>

extern Game * game;
extern QTimer * timer;
extern QMediaPlayer * music;


Health::Health(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent){
    //initialize the variables
    health = 3;

    //draw heart
   setPixmap(QPixmap(":/Zelda-Health3.png"));



}

void Health::decrease()
{
    health--;
    //gotta update the picture inside of the function increase

    if(health == 2)
    {
        setPixmap(QPixmap(":/Zelda-Health2.png"));
    }
    if(health == 1)
    {
        setPixmap(QPixmap(":/Zelda-Health.png"));

    }
    if(health <= 0)
    {
        this->hide();

        QWidget* screen = new QWidget;
        screen->setFixedSize(800,800);
        QPixmap bkgnd(":/cabgameover.png");
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        screen->setPalette(palette);

        QPushButton * back = new QPushButton();
        QIcon undo = QIcon (":/undo.png");
        back->setIconSize(QSize(130,130));
        back->setStyleSheet("QPushButton{background-color:none; border:none;}");
        back->setIcon(undo);
        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(back);
        screen->setLayout(layout);
        layout->setAlignment(Qt::AlignTop);

        screen->show();
        game->hide();
        timer->stop();
        music->stop();
        game->close();

        MainWindow * hello = new MainWindow;
        Game::connect(back, SIGNAL(clicked()), hello, SLOT(backhome()));
        Game::connect(back, SIGNAL(clicked()), screen, SLOT(close()));

    }
    //this is how you will end the game

}

void Health::increase()
{
    //only allowed a max of 3 lives
   if(health < 3)
   {
       health++;
   }

   if(health == 2)
   {
       setPixmap(QPixmap(":/Zelda-Health2.png"));
   }

   if(health == 3)
   {
       setPixmap(QPixmap(":/Zelda-Health3.png"));

   }
}

int Health::getHealth()
{
    return health;
}

