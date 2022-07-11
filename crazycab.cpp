#include "crazycab.h"
#include "mainwindow.h"

crazycab::crazycab(QWidget *parent) : QWidget(parent) {
    resize(QDesktopWidget().availableGeometry(this).size() * .8);
    setStyleSheet("background-color: lightyellow;");

    QLabel* cabheader = new QLabel("Crazy Cab!");
    cabheader->setStyleSheet("QLabel {color : blue; font: 35pt; font-weight: bold; font-family: Jokerman;}");
    cabheader->setAlignment(Qt::AlignCenter);

    QPushButton* cabhome = new QPushButton("");
    connect(cabhome, SIGNAL(clicked()), this, SLOT(backhome()));
    cabhome->setFixedSize(100,50);
    QIcon homeicon = QIcon (":/home.png");
    cabhome->setIcon(QIcon(homeicon));
    cabhome->setIconSize(QSize(50,50));
    cabhome->setStyleSheet("QPushButton {border : none}");


    QMediaPlayer* cabmusic = new QMediaPlayer();
    cabmusic->setMedia(QUrl("qrc:/lionking.mp3"));
    cabmusic->setVolume(50);
    cabmusic->play();

    QPushButton* musicbutton1 = new QPushButton("");
    connect(musicbutton1, SIGNAL(clicked()), cabmusic, SLOT(pause()));
    QPushButton* musicbutton2 = new QPushButton("");
    connect(musicbutton2, SIGNAL(clicked()), cabmusic, SLOT(play()));
    musicbutton1->setFixedSize(QSize(50,50));
    musicbutton2->setFixedSize(QSize(50,50));


    QIcon mute = QIcon (":/mute.png");
    musicbutton1->setIcon(QIcon(mute));
    musicbutton1->setIconSize(QSize(40,40));
    musicbutton1->setStyleSheet("QPushButton {border : none}");
    QIcon unmute = QIcon (":/unmute.png");
    musicbutton2->setIcon(QIcon(unmute));
    musicbutton2->setIconSize(QSize(140,140));
    musicbutton2->setStyleSheet("QPushButton {border : none}");

    connect(cabhome, SIGNAL(clicked()), cabmusic, SLOT(stop()));

    QHBoxLayout* cablay = new QHBoxLayout;
    cablay->setAlignment(Qt::AlignTop);
    cablay->addWidget(cabhome);
    cablay->addWidget(cabheader);
    cablay->addWidget(musicbutton1);
    cablay->addWidget(musicbutton2);
    this->setLayout(cablay);

}

void crazycab::backhome() {
    MainWindow* m = new MainWindow;
    m->show();
    this->hide();
}

