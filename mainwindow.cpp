#include "mainwindow.h"
#include "crazycab.h"
#include "mapmania.h"
#include "perfectpiano.h"
#include "Game.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Enemy5.h"
#include "Health.h"
#include "Score.h"
#include "Player.h"
#include "Ally.h"
#include <QTimer>
#include <QMediaPlayer>
#include "AlienGame.h"
#include "AlienEnemy.h"
#include "AlienEnemy2.h"
#include "AlienHealth.h"
#include "Bullet.h"
#include "SpaceShipPlayer.h"
#include "SpaceShipScore.h"


Game * game;
QTimer * timer;
QMediaPlayer * music;
QTimer * AlienTimer;
QMediaPlayer * AlienMusic;
AlienGame * alienGame;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
   setFixedSize(1400,800);

   setStyleSheet("background-color: lightblue;");
   setWindowTitle("KidsKorner");

   const QSize btnSize = QSize(300,300);
   const QSize dirsize = QSize(400,50);

   QPushButton* button1 = new QPushButton;
   QPushButton* button2 = new QPushButton;
   QPushButton* button3 = new QPushButton;
   QPushButton* button4 = new QPushButton;

   QIcon icon1 = QIcon (":/taxi.png");
   QIcon icon2 = QIcon (":/trivia.png");
   QIcon icon3 = QIcon (":/balls.png");
   QIcon icon4 = QIcon (":/piano.png");

   button1->setIcon(QIcon(icon1));
   button1->setIconSize(QSize(280,280));
   button2->setIcon(QIcon(icon2));
   button2->setIconSize(QSize(280,280));
   button3->setIcon(QIcon(icon3));
   button3->setIconSize(QSize(350,350));
   button4->setIcon(QIcon(icon4));
   button4->setIconSize(QSize(500,500));

   button1->setStyleSheet("QPushButton {border : none; background-color:darkcyan; border-radius:15px;}");
   button2->setStyleSheet("QPushButton {border : none; background-color:darkcyan; border-radius:15px;}");
   button3->setStyleSheet("QPushButton {border : none; background-color:darkcyan; border-radius:15px;}");
   button4->setStyleSheet("QPushButton {border : none; background-color:darkcyan; border-radius:15px;}");

   button1->setFixedSize(btnSize);
   button2->setFixedSize(btnSize);
   button3->setFixedSize(btnSize);
   button4->setFixedSize(btnSize);

   QLabel* text = new QLabel("Welcome to Kids Korner!");
   QLabel* math = new QLabel("Crazy Cab");
   QLabel* trivia = new QLabel("Map Mania");
   QLabel* balls = new QLabel("Bouncing Balls");
   QLabel* piano = new QLabel("Perfect Piano");

   text->setStyleSheet("QLabel {color : yellow; font: 40pt; font-weight: bold; font-family: Jokerman;}");
   text->setAlignment(Qt::AlignCenter);
   math->setStyleSheet("QLabel {color : darkblue; font: 16pt; font-weight: bold; font-family: Curlz MT;}");
   math->setAlignment(Qt::AlignCenter);
   trivia->setStyleSheet("QLabel {color : darkblue; font: 16pt; font-weight: bold; font-family: Curlz MT;}");
   trivia->setAlignment(Qt::AlignCenter);
   balls->setStyleSheet("QLabel {color : darkblue; font: 16pt; font-weight: bold; font-family: Curlz MT;}");
   balls->setAlignment(Qt::AlignCenter);
   piano->setStyleSheet("QLabel {color : darkblue; font: 16pt; font-weight: bold; font-family: Curlz MT;}");
   piano->setAlignment(Qt::AlignCenter);

   QPushButton* instructions = new QPushButton("Instructions");
   instructions->setFixedSize(650, 60);
   instructions->setStyleSheet("QPushButton {border: none; background-color: darkcyan; color: white; font: 18pt; border-radius:15px; font-weight: bold; font-family: Curlz MT;}");

   QHBoxLayout* instructlay = new QHBoxLayout;
   instructlay->setAlignment(Qt::AlignCenter);
   instructlay->addWidget(instructions);

   QVBoxLayout* Vlayout = new QVBoxLayout;
   QHBoxLayout* Hlayout2 = new QHBoxLayout;
   QHBoxLayout* Hlayout3 = new QHBoxLayout;

   QVBoxLayout* mathlayout = new QVBoxLayout;
   mathlayout->setAlignment(Qt::AlignCenter);
   QVBoxLayout* trivialayout = new QVBoxLayout;
   trivialayout->setAlignment(Qt::AlignCenter);
   QVBoxLayout* ballslayout = new QVBoxLayout;
   ballslayout->setAlignment(Qt::AlignCenter);
   QVBoxLayout* pianolayout = new QVBoxLayout;
   pianolayout->setAlignment(Qt::AlignCenter);

   mathlayout->addWidget(button1);
   trivialayout->addWidget(button2);
   ballslayout->addWidget(button3);
   pianolayout->addWidget(button4);

   QMovie* movie = new QMovie(":/kid.gif");
   QLabel* processLabel = new QLabel(this);
   processLabel->setAlignment(Qt::AlignCenter);
   processLabel->setFixedSize(QSize(700,300));
   processLabel->setMovie(movie);
   movie->start();

   Hlayout2->addWidget(processLabel);
   Hlayout3->addLayout(trivialayout);
   Hlayout3->addLayout(pianolayout);
   Hlayout3->addLayout(mathlayout);
   Hlayout3->addLayout(ballslayout);

   Vlayout->addWidget(text);
   Vlayout->addLayout(Hlayout2);
   Vlayout->addLayout(instructlay);
   Vlayout->addLayout(Hlayout3);
   QWidget* central = new QWidget();
   this->setCentralWidget(central);
   central->setLayout(Vlayout);
   connect(button1, SIGNAL(clicked()), this, SLOT(buttonpressed1()));
   connect(button2, SIGNAL(clicked()), this, SLOT(buttonpressed2()));
   connect(button3, SIGNAL(clicked()), this, SLOT(buttonpressed3()));
   connect(button4, SIGNAL(clicked()), this, SLOT(buttonpressed4()));
   connect(instructions, SIGNAL(clicked()), this, SLOT(directionspressed()));
}

void MainWindow::directionspressed()
{
    QLabel* instructions = new QLabel("Learn and play!                                                                                                 Name the places of the world and practice playing the piano!                                   Then enjoy the fun games like Crazy Cab and Aliens Attack!                                       Close this window and choose an icon to start playing!");
    instructions->setStyleSheet("QLabel{color : darkblue; background-color: lightyellow; font: 12pt; font-weight: bold; font-family: Comic Sans MS}");
    instructions->setFixedSize(750,300);
    instructions->setAlignment(Qt::AlignCenter);
    instructions->setWordWrap(true);
    instructions->show();
}

void MainWindow::buttonpressed1() {
    game = new Game();
    game->show();
    this->hide();
}

void MainWindow::buttonpressed2() {
    mapmania* m = new mapmania;
    m->show();
    this->hide();
}

void MainWindow::buttonpressed3() {
    alienGame = new AlienGame();
    alienGame->show();
    this->hide();

}

void MainWindow::buttonpressed4() {
    perfectpiano* o = new perfectpiano;
    o->show();
    this->hide();
}

MainWindow::~MainWindow()
{
}

