#ifndef MAPMANIA_H
#define MAPMANIA_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMediaPlayer>

class mapmania : public QWidget
{
    Q_OBJECT
public:
    explicit mapmania(QWidget *parent = nullptr);

private:
    QVBoxLayout* maplayout;
    QLabel* question;
    QLabel* score;
    int right;
    QPushButton* state;
    QPushButton* option1;
    QPushButton* option2;
    QPushButton* option3;
    QHBoxLayout* questionlay;
    QHBoxLayout* maptitle;
    QHBoxLayout* statelay;
    QHBoxLayout* buttonlay;
    QVBoxLayout* addlay;
    QPushButton* instruct;
    QLabel* level;
    QPushButton* begin;
    QLabel* finalscore;
    QVBoxLayout* levellay;
    QHBoxLayout* usalay;
    QLabel* gameover;
    QPushButton* backlevel1;
    QVBoxLayout* overlay;
    QMediaPlayer* correctanswer;
    QMediaPlayer* wronganswer;

public slots:
    void backhome();
    void mute();
    void unmute();
    void correct();
    void correctsound();
    void wrongsound();
    void deletethis();
    void enddelete();
    void instructions();
    void level1();
    void layout1();
    void layout2();
    void layout3();
    void layout4();
    void layout5();
    void level2();
    void layout6();
    void layout7();
    void layout8();
    void layout9();
    void layout10();
    void level3();
    void layout11();
    void layout12();
    void layout13();
    void layout14();
    void layout15();
    void end();
};

#endif // MAPMANIA_H
