#include "AlienHealth.h"
#include "QGraphicsTextItem"
#include <QFont>
#include <QDebug>
#include <QLabel>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include "AlienGame.h"
#include "mainwindow.h"

extern QTimer * AlienTimer;
extern QMediaPlayer * AlienMusic;
extern AlienGame * alienGame;

AlienHealth::AlienHealth(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent){
    //initialize the variables
    health = 3;

    //draw heart
   setPixmap(QPixmap(":/Zelda-Health3.png"));

}

void AlienHealth::decrease()
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

    if(health == 0)
    {        
        this->hide();

        QWidget * screen = new QWidget;
        screen->setFixedSize(920,630);
        QPixmap bkgnd(":/aliengameover.jpg");
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        screen->setPalette(palette);

        QPushButton * back = new QPushButton();
        QIcon undo = QIcon (":/whiteundo.png");
        back->setIconSize(QSize(130,130));
        back->setStyleSheet("QPushButton{background-color:none; border:none;}");
        back->setIcon(undo);
        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(back);
        screen->setLayout(layout);
        layout->setAlignment(Qt::AlignTop);

        screen->show();
        alienGame->hide();
        AlienTimer->stop();
        AlienMusic->stop();
        alienGame->close();

        MainWindow * hello = new MainWindow;
        AlienGame::connect(back, SIGNAL(clicked()), hello, SLOT(backhome()));
        AlienGame::connect(back, SIGNAL(clicked()), screen, SLOT(close()));
    }
    //this is how you will end the game

}

int AlienHealth::getHealth()
{
    return health;
}
