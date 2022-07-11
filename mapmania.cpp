#include "mapmania.h"
#include "mainwindow.h"
#include <QDesktopWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QIcon>

mapmania::mapmania(QWidget *parent) : QWidget(parent) {
    this->setFixedSize(QDesktopWidget().availableGeometry(this).size() * .8);

    QPixmap bkgnd(":/back.png");
    bkgnd = bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QLabel* mapheader = new QLabel("Map Mania!");
    mapheader->setStyleSheet("QLabel {color : blue; font: 35pt; font-weight: bold; font-family: Jokerman;}");
    mapheader->setAlignment(Qt::AlignCenter);

    QPushButton* maphome = new QPushButton;
    connect(maphome, SIGNAL(clicked()), this, SLOT(backhome())); //takes you back to welcome page
    maphome->setFixedSize(100,50);
    QIcon maphomeicon = QIcon (":/home.png");
    maphome->setIcon(QIcon(maphomeicon));
    maphome->setIconSize(QSize(50,50));
    maphome->setStyleSheet("QPushButton {border : none}");

    correctanswer = new QMediaPlayer;
    correctanswer->setMedia(QUrl("qrc:/correctans.mp3"));
    correctanswer->setVolume(50);

    wronganswer = new QMediaPlayer;
    wronganswer->setMedia(QUrl("qrc:/wrongans.mp3"));
    wronganswer->setVolume(50);

    QPushButton* musicbutton1 = new QPushButton("");
    connect(musicbutton1, SIGNAL(clicked()), this, SLOT(mute())); //mutes sound
    QPushButton* musicbutton2 = new QPushButton("");
    connect(musicbutton2, SIGNAL(clicked()), this, SLOT(unmute())); //plays sound
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

    maptitle = new QHBoxLayout;
    maptitle->setAlignment(Qt::AlignTop);
    maptitle->addWidget(maphome);
    maptitle->addWidget(mapheader);
    maptitle->addWidget(musicbutton1);
    maptitle->addWidget(musicbutton2);

    maplayout = new QVBoxLayout;
    maplayout->addLayout(maptitle);
    this->setLayout(maplayout);

    level1();
}

void mapmania::backhome() {
    MainWindow* m = new MainWindow;
    m->show();
    this->hide();
}

void mapmania::mute() {
    correctanswer->setVolume(0);
    wronganswer->setVolume(0);
}

void mapmania::unmute() {
    correctanswer->setVolume(50);
    wronganswer->setVolume(50);
}

//adds to score
void mapmania::correct() {
    ++right;
    score->setText("Score: " + QString::fromStdString(std::to_string(right)) + " / 5");
    disconnect(option1, SIGNAL(clicked()), this, SLOT(correct()));
    disconnect(option2, SIGNAL(clicked()), this, SLOT(correct()));
    disconnect(option3, SIGNAL(clicked()), this, SLOT(correct()));
}

//plays correct sound when user chooses the correct answer
void mapmania::correctsound() {
    correctanswer->play();
    wronganswer->stop();
    disconnect(option1, SIGNAL(clicked()), this, SLOT(correctsound()));
    disconnect(option2, SIGNAL(clicked()), this, SLOT(correctsound()));
    disconnect(option3, SIGNAL(clicked()), this, SLOT(correctsound()));
}

//plays wrong sound when user chooses a wrong answer
void mapmania::wrongsound() {
   wronganswer->play();
   correctanswer->stop();
   disconnect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
   disconnect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
   disconnect(option3, SIGNAL(clicked()), this, SLOT(wrongsound()));
}

void mapmania::deletethis() {
    delete addlay;
    delete overlay;
    delete gameover;
    delete backlevel1;
    delete score;
}

void mapmania::enddelete() {
    delete addlay;
    delete levellay;
    delete instruct;
    delete begin;
    delete level;
    delete finalscore;
    delete question;
    delete score;
    delete state;
    delete option1;
    delete option2;
    delete option3;

    level1();
}

//insructions screen
void mapmania::instructions() {
    QWidget * screen = new QWidget;
    screen->setFixedSize(1100,300);
    screen->setStyleSheet("background-color: lightblue;");
    QLabel* dirheader = new QLabel("Instructions!");
    dirheader->setStyleSheet("QLabel {color : lightyellow; font: 35pt; font-weight: bold; font-family: Jokerman;}");
    dirheader->setAlignment(Qt::AlignCenter);

    QLabel* details1 = new QLabel("Test your knowledge of U.S. states, countries and continents!");
    QLabel* details2 = new QLabel("There are 3 levels each with 5 questions. Get at least 3 questions right to move on to the next level");
    QLabel* details3 = new QLabel("To win: Successfully complete all 3 levels!");

    details1->setAlignment(Qt::AlignCenter);
    details2->setAlignment(Qt::AlignCenter);
    details3->setAlignment(Qt::AlignCenter);

    details1->setStyleSheet("QLabel{color : darkblue; font: 10pt; font-weight: bold; font-family: Comic Sans MS}");
    details2->setStyleSheet("QLabel{color : darkblue; font: 10pt; font-weight: bold; font-family: Comic Sans MS}");
    details3->setStyleSheet("QLabel{color : darkblue; font: 10pt; font-weight: bold; font-family: Comic Sans MS}");

    QVBoxLayout* dirlay = new QVBoxLayout;
    dirlay->setAlignment(Qt::AlignTop);
    dirlay->addWidget(dirheader);
    dirlay->addWidget(details1);
    dirlay->addWidget(details2);
    dirlay->addWidget(details3);
    screen->setLayout(dirlay);

    screen->show();
}

void mapmania::level1() {
    level = new QLabel("Level 1");
    level->setStyleSheet("QLabel {color : black; font: 25pt; font-weight: bold}");
    level->setAlignment(Qt::AlignCenter);
    begin = new QPushButton("Begin");
    begin->setFixedSize(QSize(300,100));
    begin->setStyleSheet("QPushButton {background-color: lightyellow; border-radius:15px; font-family: Comic Sans MS; font: 20pt; font-weight: bold}");
    connect(begin, SIGNAL(clicked()), this, SLOT(layout1())); //displays 1st question of level 1


    instruct = new QPushButton("Instructions");
    instruct->setFixedSize(QSize(300, 50));
    instruct->setStyleSheet("QPushButton {background-color: pink; border-radius: 15px; font-family: Comic Sans MS; font: 12pt; font-weight: bold}");
    connect(instruct, SIGNAL(clicked()), this, SLOT(instructions())); //opens instructions window

    levellay = new QVBoxLayout;
    levellay->setAlignment(Qt::AlignCenter);
    levellay->addWidget(instruct);
    levellay->addWidget(level);
    levellay->addWidget(begin);

    maplayout->addLayout(levellay);
}

//U.S. state questions begin
void mapmania::layout1() {
    level->hide();
    begin->hide();
    instruct->hide();
    question = new QLabel("What U.S. state is this?");
    question->setStyleSheet("QLabel {color: lightpink; font: 20pt; font-weight: bold; font-family: Comic Sans MS}");
    question->setAlignment(Qt::AlignLeft);

    right = 0;
    score = new QLabel(("Score: " + QString::fromStdString(std::to_string(right)) + " / 5"));
    score->setStyleSheet("QLabel {color: black; font: 10pt; font-weight: bold; font-family: Comic Sans MS}");
    score->setAlignment(Qt::AlignRight);

    state = new QPushButton;
    QIcon cali = QIcon (":/cali.jpg");
    state->setIcon(cali);
    state->setStyleSheet("QPushButton {border: none}");
    state->setFixedSize(QSize(400,400));
    state->setIconSize(QSize(400,400));

    option1 = new QPushButton("California");
    option2 = new QPushButton("Florida");
    option3 = new QPushButton("Nevada");
    option1->setFixedSize(QSize(250,50));
    option2->setFixedSize(QSize(250,50));
    option3->setFixedSize(QSize(250,50));
    option1->setStyleSheet("QPushButton {background-color: pink; border-radius:15px; font-family: Comic Sans MS; font: 11pt; font-weight: bold}");
    option2->setStyleSheet("QPushButton {background-color: pink; border-radius:15px; font-family: Comic Sans MS; font: 11pt; font-weight: bold}");
    option3->setStyleSheet("QPushButton {background-color: pink; border-radius:15px; font-family: Comic Sans MS; font: 11pt; font-weight: bold}");

    connect(option1, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option1, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option3, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout2()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout2()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout2()));

    questionlay = new QHBoxLayout;
    questionlay->setAlignment(Qt::AlignTop);
    questionlay->addSpacing(130);
    questionlay->addWidget(question);
    questionlay->addWidget(score);
    questionlay->addSpacing(130);

    statelay = new QHBoxLayout;
    statelay->addWidget(state);
    statelay->setAlignment(Qt::AlignCenter);

    buttonlay = new QHBoxLayout;
    buttonlay->addWidget(option1);
    buttonlay->addWidget(option2);
    buttonlay->addWidget(option3);

    addlay = new QVBoxLayout;
    addlay->addLayout(questionlay);
    addlay->addSpacing(20);
    addlay->addLayout(statelay);
    addlay->addSpacing(20);
    addlay->addLayout(buttonlay);
    addlay->addSpacing(90);

    maplayout->removeItem(levellay);
    maplayout->addLayout(addlay);
}

void mapmania::layout2() {
    QIcon lou = QIcon (":/lou.jpg");
    state->setIcon(lou);

    option1->setText("Georgia");
    option2->setText("Mississppi");
    option3->setText("Louisiana");

    connect(option3, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option3, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout3()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout3()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout3()));
}

void mapmania::layout3() {
    QIcon wis = QIcon (":/wis.jpg");
    state->setIcon(wis);

    option1->setText("Wisconsin");
    option2->setText("Michigan");
    option3->setText("Minnesota");

    connect(option1, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option1, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option3, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout4()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout4()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout4()));
}

void mapmania::layout4() {
    QIcon ark = QIcon (":/ark.jpg");
    state->setIcon(ark);

    option1->setText("Missouri");
    option2->setText("Illinois");
    option3->setText("Arkansas");

    connect(option3, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option3, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout5()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout5()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout5()));
}

void mapmania::layout5() {
    QIcon wash = QIcon (":/wash.jpg");
    state->setIcon(wash);

    option1->setText("Montana");
    option2->setText("Washington");
    option3->setText("Oregon");


    connect(option2, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option2, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option3, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(level2()));
    connect(option2, SIGNAL(clicked()), this, SLOT(level2()));
    connect(option3, SIGNAL(clicked()), this, SLOT(level2()));

    disconnect(option1, SIGNAL(clicked()), this, SLOT(correct()));
    disconnect(option3, SIGNAL(clicked()), this, SLOT(correct()));
    disconnect(option1, SIGNAL(clicked()), this, SLOT(correctsound()));
    disconnect(option3, SIGNAL(clicked()), this, SLOT(correctsound()));
    disconnect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));

}


void mapmania::level2() {
    //if user wins level 1
    if (right >= 3) {
        question->hide();
        score->hide();
        state->hide();
        option1->hide();
        option2->hide();
        option3->hide();
        level->show();
        begin->show();
        level->setText("Level 2");
        finalscore = new QLabel(("Score: " + QString::fromStdString(std::to_string(right)) + " / 5"));
        finalscore->setStyleSheet("QLabel {color: black; font: 10pt; font-weight: bold; font-family: Comic Sans MS}");
        levellay->removeWidget(level);
        levellay->removeWidget(begin);
        levellay->addWidget(finalscore);
        finalscore->setAlignment(Qt::AlignCenter);
        levellay->addWidget(level);
        levellay->addWidget(begin);

        connect(begin, SIGNAL(clicked()), this, SLOT(layout6())); //user moves on to level 2

        maplayout->removeItem(addlay);
        maplayout->addLayout(levellay);
     }
    //if user loses level 1
     else {
        delete question;
        delete state;
        delete option1;
        delete option2;
        delete option3;
        delete level;
        delete begin;
        gameover = new QLabel("Game Over");
        gameover->setStyleSheet("QLabel {color : black; font: 25pt; font-weight: bold;}");
        gameover->setAlignment(Qt::AlignCenter);
        backlevel1 = new QPushButton("Play from Beginnging");
        backlevel1->setFixedSize(QSize(300, 100));
        backlevel1->setStyleSheet("QPushButton {background-color: pink; border-radius:15px; font-family: Comic Sans MS; font: 12pt; font-weight: bold}");
        connect(backlevel1, SIGNAL(clicked()), this, SLOT(level1())); //game starts from beginning
        connect(backlevel1, SIGNAL(clicked()), this, SLOT(deletethis()));
        overlay = new QVBoxLayout;
        overlay->setAlignment(Qt::AlignCenter);
        overlay->addWidget(score);
        score->setAlignment(Qt::AlignCenter);
        overlay->addWidget(gameover);
        overlay->addWidget(backlevel1);

        maplayout->removeItem(addlay);
        maplayout->addLayout(overlay);
     }
}

//country questions begin
void mapmania::layout6() {
    level->hide();
    begin->hide();
    finalscore->hide();
    level->hide();
    begin->hide();
    score->show();
    question->show();
    state->show();
    option1->show();
    option2->show();
    option3->show();

    option1->disconnect();
    option2->disconnect();
    option3->disconnect();

    question->setText("What country is this?");

    QIcon italy = QIcon (":/italy.png");
    state->setIcon(italy);

    option1->setText("Philippines");
    option2->setText("New Zealand");
    option3->setText("Italy");


    connect(option3, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option3, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout7()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout7()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout7()));
}

void mapmania::layout7() {
    QIcon spain = QIcon (":/spain.png");
    state->setIcon(spain);

    option1->setText("France");
    option2->setText("Spain");
    option3->setText("Poland");

    connect(option2, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option2, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option3, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout8()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout8()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout8()));
}

void mapmania::layout8() {
    QIcon brazil = QIcon (":/brazil.jpg");
    state->setIcon(brazil);

    option1->setText("Columbia");
    option2->setText("Brazil");
    option3->setText("Venezuela");

    connect(option2, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option2, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option3, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout9()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout9()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout9()));
}

void mapmania::layout9() {
    QIcon ny = QIcon (":/ukraine.png");
    state->setIcon(ny);

    option1->setText("Bulgaria");
    option2->setText("Romania");
    option3->setText("Ukraine");

    connect(option3, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option3, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout10()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout10()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout10()));
 }

void mapmania::layout10() {
    QIcon ndak = QIcon (":/tan.PNG");
    state->setIcon(ndak);

    option1->setText("Tanzania");
    option2->setText("Kenya");
    option3->setText("Ethiopia");

    connect(option1, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option1, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option3, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(level3()));
    connect(option2, SIGNAL(clicked()), this, SLOT(level3()));
    connect(option3, SIGNAL(clicked()), this, SLOT(level3()));

    disconnect(option2, SIGNAL(clicked()), this, SLOT(correct()));
    disconnect(option3, SIGNAL(clicked()), this, SLOT(correct()));
    disconnect(option2, SIGNAL(clicked()), this, SLOT(correctsound()));
    disconnect(option3, SIGNAL(clicked()), this, SLOT(correctsound()));
    disconnect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
}

void mapmania::level3() {
    //user wins level 2
    if (right >= 3) {
        question->hide();
        score->hide();
        state->hide();
        option1->hide();
        option2->hide();
        option3->hide();
        finalscore->show();
        level->show();
        begin->show();
        level->setText("Level 3");
        finalscore->setText("Score: " + QString::fromStdString(std::to_string(right)) + " / 5");
        finalscore->setStyleSheet("QLabel {color: black; font: 10pt; font-weight: bold; font-family: Comic Sans MS}");
        levellay->removeWidget(level);
        levellay->removeWidget(begin);
        levellay->addWidget(finalscore);
        finalscore->setAlignment(Qt::AlignCenter);
        levellay->addWidget(level);
        levellay->addWidget(begin);

        connect(begin, SIGNAL(clicked()), this, SLOT(layout11())); //user moves on to level 3

        maplayout->removeItem(addlay);
        maplayout->addLayout(levellay);
     }
    //user loses level 2
     else {
        delete question;
        delete state;
        delete option1;
        delete option2;
        delete option3;
        delete level;
        delete begin;
        gameover = new QLabel("Game Over");
        gameover->setStyleSheet("QLabel {color : black; font: 25pt; font-weight: bold;}");
        gameover->setAlignment(Qt::AlignCenter);
        backlevel1 = new QPushButton("Play from Beginnging");
        backlevel1->setStyleSheet("QPushButton {background-color: pink; border-radius:15px; font-family: Comic Sans MS; font: 12pt; font-weight: bold}");
        backlevel1->setFixedSize(QSize(300, 100));
        connect(backlevel1, SIGNAL(clicked()), this, SLOT(level1()));
        connect(backlevel1, SIGNAL(clicked()), this, SLOT(deletethis()));
        overlay = new QVBoxLayout;
        overlay->setAlignment(Qt::AlignCenter);
        overlay->addWidget(score);
        score->setAlignment(Qt::AlignCenter);
        overlay->addWidget(gameover);
        overlay->addWidget(backlevel1);

        maplayout->removeItem(addlay);
        maplayout->addLayout(overlay);
     }
}

//continent questions begin
void mapmania::layout11() {
    finalscore->hide();
    level->hide();
    begin->hide();
    score->show();
    question->show();
    state->show();
    option1->show();
    option2->show();
    option3->show();

    option1->disconnect();
    option2->disconnect();
    option3->disconnect();

    question->setText("What continent is this?");

    QIcon cali = QIcon (":/africa.png");
    state->setIcon(cali);

    option1->setText("Africa");
    option2->setText("South America");
    option3->setText("Asia");


    connect(option1, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option1, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option3, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout12()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout12()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout12()));
}

void mapmania::layout12() {
    QIcon okla = QIcon (":/aus.png");
    state->setIcon(okla);

    option1->setText("Europe");
    option2->setText("Australia");
    option3->setText("Asia");

    connect(option2, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option2, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option3, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout13()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout13()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout13()));
}

void mapmania::layout13() {
    QIcon iowa = QIcon (":/sa.jpg");
    state->setIcon(iowa);

    option1->setText("North America");
    option2->setText("Africa");
    option3->setText("South America");

    connect(option3, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option3, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout14()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout14()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout14()));
}

void mapmania::layout14() {
    QIcon ny = QIcon (":/asia.png");
    state->setIcon(ny);

    option1->setText("North America");
    option2->setText("Europe");
    option3->setText("Asia");

    connect(option3, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option3, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(layout15()));
    connect(option2, SIGNAL(clicked()), this, SLOT(layout15()));
    connect(option3, SIGNAL(clicked()), this, SLOT(layout15()));
 }

void mapmania::layout15() {
    QIcon ndak = QIcon (":/europe.png");
    state->setIcon(ndak);

    option1->setText("Europe");
    option2->setText("Asia");
    option3->setText("Antartica");

    connect(option1, SIGNAL(clicked()), this, SLOT(correct()));
    connect(option1, SIGNAL(clicked()), this, SLOT(correctsound()));
    connect(option2, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option3, SIGNAL(clicked()), this, SLOT(wrongsound()));
    connect(option1, SIGNAL(clicked()), this, SLOT(end()));
    connect(option2, SIGNAL(clicked()), this, SLOT(end()));
    connect(option3, SIGNAL(clicked()), this, SLOT(end()));

    disconnect(option2, SIGNAL(clicked()), this, SLOT(correct()));
    disconnect(option3, SIGNAL(clicked()), this, SLOT(correct()));
    disconnect(option2, SIGNAL(clicked()), this, SLOT(correctsound()));
    disconnect(option3, SIGNAL(clicked()), this, SLOT(correctsound()));
    disconnect(option1, SIGNAL(clicked()), this, SLOT(wrongsound()));
}

void mapmania::end() {
    //user wins level 3
    if (right >= 3) {
        question->hide();
        score->hide();
        state->hide();
        option1->hide();
        option2->hide();
        option3->hide();
        finalscore->show();
        level->show();
        begin->show();

        //user wins game and can restart from the beginning
        level->setText("You Win!");
        finalscore->setText("Score: " + QString::fromStdString(std::to_string(right)) + " / 5");
        finalscore->setStyleSheet("QLabel {color: black; font: 10pt; font-weight: bold; font-family: Comic Sans MS}");
        begin->setStyleSheet("QPushButton {background-color: lightyellow; border-radius: 15px; font-family: Comic Sans MS; font: 12pt; font-weight: bold}");
        begin->setText("Play from Beginning");
        levellay->removeWidget(level);
        levellay->removeWidget(begin);
        levellay->addWidget(finalscore);
        finalscore->setAlignment(Qt::AlignCenter);
        levellay->addWidget(level);
        levellay->addWidget(begin);

        maplayout->removeItem(addlay);

        connect(begin, SIGNAL(clicked()), this, SLOT(enddelete()));

        maplayout->addLayout(levellay);
     }
    //user loses level 3
     else {
        delete question;
        delete state;
        delete option1;
        delete option2;
        delete option3;
        delete level;
        delete begin;
        gameover = new QLabel("Game Over");
        gameover->setStyleSheet("QLabel {color : black; font: 25pt; font-weight: bold;}");
        gameover->setAlignment(Qt::AlignCenter);
        backlevel1 = new QPushButton("Play from Beginnging");
        backlevel1->setStyleSheet("QPushButton {background-color: pink; border-radius:15px; font-family: Comic Sans MS; font: 12pt; font-weight: bold}");
        backlevel1->setFixedSize(QSize(300, 100));
        connect(backlevel1, SIGNAL(clicked()), this, SLOT(level1())); //restarts game
        connect(backlevel1, SIGNAL(clicked()), this, SLOT(deletethis()));
        overlay = new QVBoxLayout;
        overlay->setAlignment(Qt::AlignCenter);
        overlay->addWidget(score);
        score->setAlignment(Qt::AlignCenter);
        overlay->addWidget(gameover);
        overlay->addWidget(backlevel1);

        maplayout->removeItem(addlay);
        maplayout->addLayout(overlay);
     }
}





