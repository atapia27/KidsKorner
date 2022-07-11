#include "SpaceShipScore.h"
#include "QGraphicsTextItem"
#include <QFont>
#include <QPushButton>
#include <QBoxLayout>
#include <QMediaPlayer>
#include <QTimer>
#include "mainwindow.h"
#include "AlienGame.h"
#include "AlienEnemy.h"
#include "AlienHealth.h"

extern QTimer * AlienTimer;
extern QMediaPlayer * AlienMusic;
extern AlienGame * alienGame;

SpaceShipScore::SpaceShipScore(QGraphicsItem *parent) : QGraphicsTextItem(parent){
    //initialize the variables
    score = 0;

    //draw text
    setPlainText(QString("SCORE : ") + QString::number(score));

    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 12));    
}

void SpaceShipScore::increase()
{
    score++;
    //gotta update the text inside of the function increase
    setPlainText(QString("SCORE : ") + QString::number(score));

    if (score == 3)
    {
        this->hide();

        QWidget * screen = new QWidget;
        screen->setFixedSize(1000,630);
        QPixmap bkgnd(":/spacewin.jpg");
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
        alienGame->hide();
        AlienTimer->stop();
        alienGame->close();
        AlienMusic->stop();

        MainWindow * hello = new MainWindow;
        AlienGame::connect(back, SIGNAL(clicked()), hello, SLOT(backhome()));
        AlienGame::connect(back, SIGNAL(clicked()), screen, SLOT(close()));
    }
}

int SpaceShipScore::getScore()
{
    return score;
}
