#include "Score.h"
#include "QGraphicsTextItem"
#include <QFont>
#include <QWidget>
#include "Health.h"
#include "Game.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QPushButton>

extern Game* game;
extern QTimer * timer;
extern QMediaPlayer * music;

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent){
    //initialize the variables
    score = 0;

    //draw text
    setPlainText(QString("SCORE : ") + QString::number(score));

    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 12));


}

void Score::increase()
{
    score++;
    //gotta update the text inside of the function increase
    setPlainText(QString("SCORE : ") + QString::number(score));

    if (score >= 30)
    {
        this->hide();

        QWidget * screen = new QWidget;
        screen->setFixedSize(800,800);
        QPixmap bkgnd(":/cabwin.png");
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
}

int Score::getScore()
{
    return score;
}
