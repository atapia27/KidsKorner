#ifndef PERFECTPIANO_H
#define PERFECTPIANO_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>

class perfectpiano : public QWidget
{
    Q_OBJECT
public:
    explicit perfectpiano(QWidget *parent = nullptr);
    QLabel* notes = new QLabel;
    QHBoxLayout* perlay = new QHBoxLayout;
    QVBoxLayout* songswithnotes = new QVBoxLayout;
    QHBoxLayout* whitepiano = new QHBoxLayout;
    QVBoxLayout* endlayout = new QVBoxLayout;
    QLabel* hints = new QLabel();

public slots:
    void backhome();
    void help();
    void showhints();
    void hidehints();
    void playc3();
    void playd3();
    void playe3();
    void playf3();
    void playg3();
    void playa4();
    void playb4();
    void playc4();
    void playd4();
    void playe4();
    void playf4();
    void playg4();
    void playa5();
    void playb5();
    void black1();
    void black2();
    void black3();
    void black4();
    void black5();
    void black6();
    void black7();
    void black8();
    void black9();
    void black0();
    void freestyle();
    void yankee();
    void itsy();
    void row();
    void barney();
    void mary();


};

#endif // PERFECTPIANO_H

