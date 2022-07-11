#include "perfectpiano.h"
#include "mainwindow.h"

#include <QObject>
#include <QShortcut>
#include <QStackedWidget>
#include <QPointer>
#include <QComboBox>
#include <QMenu>
#include <QMenuBar>
#include <QToolButton>
#include <QAction>
#include <QWidgetAction>

perfectpiano::perfectpiano(QWidget *parent) : QWidget(parent) {
    this->setFixedSize(1400,800);
    setStyleSheet("background-color: pink;");

    QLabel* perheader = new QLabel("Perfect Piano");
    perheader->setStyleSheet("QLabel {color : darkred; font: 35pt; font-weight: bold; font-family: Jokerman;}");
    perheader->setAlignment(Qt::AlignCenter);

    QPushButton* perhome = new QPushButton(""); //adds a home button to return to main page
    connect(perhome, SIGNAL(clicked()), this, SLOT(backhome()));
    perhome->setFixedSize(100,50);
    QIcon homeicon = QIcon (":/home.png");
    perhome->setIcon(QIcon(homeicon));
    perhome->setIconSize(QSize(50,50));
    perhome->setStyleSheet("QPushButton {border : none}");

    QPushButton* pianomenu = new QPushButton(""); //adds a menu button to return to main page
    connect(pianomenu, SIGNAL(clicked()), this, SLOT(backhome()));
    pianomenu->setFixedSize(100,50);
    QIcon menuicon = QIcon (":/piano_menu.png");
    pianomenu->setIcon(QIcon(menuicon));
    pianomenu->setIconSize(QSize(50,50));
    pianomenu->setStyleSheet("QPushButton {border : none}");

    QWidgetAction* help = new QWidgetAction(this); //creates an action for the help menu
    QLabel *num = new QLabel(tr("Help")); //assigns action to label so that qpaintevent can be activated
    num->setAlignment(Qt::AlignCenter);
    num->setStyleSheet("QLabel {color : darkblue; font: 12pt; font-weight: bold;}");
    help->setDefaultWidget(num);
    connect(help,SIGNAL(triggered()),this,SLOT(help()));

    QWidgetAction* showhints = new QWidgetAction(this); //creates an action for the help menu
    QLabel *num1 = new QLabel(tr("Show Hints")); //assigns action to label so that qpaintevent can be activated
    num1->setAlignment(Qt::AlignCenter);
    num1->setStyleSheet("QLabel {color : darkblue; font: 12pt; font-weight: bold;}");
    showhints->setDefaultWidget(num1);
    connect(showhints,SIGNAL(triggered()),this,SLOT(showhints()));

    QWidgetAction* hidehints = new QWidgetAction(this); //creates an action for the help menu
    QLabel *num2 = new QLabel(tr("Hide Hints")); //assigns action to label so that qpaintevent can be activated
    num2->setAlignment(Qt::AlignCenter);
    num2->setStyleSheet("QLabel {color : darkblue; font: 12pt; font-weight: bold;}");
    hidehints->setDefaultWidget(num2);
    connect(hidehints,SIGNAL(triggered()),this,SLOT(hidehints()));

    QMenu* pmenu = new QMenu(); //creates a menu to add actions to
    pmenu->addAction(help);
    pmenu->addSeparator();
    pmenu->addAction(showhints);
    pmenu->addSeparator();
    pmenu->addAction(hidehints);
    pianomenu->setMenu(pmenu);

    perlay->setAlignment(Qt::AlignTop);
    perlay->addWidget(perhome);
    perlay->addWidget(perheader);
    perlay->addWidget(pianomenu);

    /*
    QPushButton c3-g3, a4-g4, and a5-b5 create buttons for the piano keys
    QShortcut c3short-g3short, a4short-g4short, and a5short-b5short create keyboard shortcuts that connect letters on the keyboard to buttons
    */

    QPushButton* c3 = new QPushButton("A");
    c3->setFixedHeight(500);
    c3->setFixedWidth(100);
    c3->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *c3short = new QShortcut(QKeySequence(Qt::Key_A), c3);
    QObject::connect(c3, SIGNAL(clicked()), this, SLOT(playc3()));
    QObject::connect(c3short, SIGNAL(activated()), c3, SLOT(animateClick()));

    QPushButton* d3 = new QPushButton("Q");
    d3->setFixedHeight(500);
    d3->setFixedWidth(100);
    d3->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *d3short = new QShortcut(QKeySequence(Qt::Key_Q), d3);
    QObject::connect(d3, SIGNAL(clicked()), this, SLOT(playd3()));
    QObject::connect(d3short, SIGNAL(activated()), d3, SLOT(animateClick()));

    QPushButton* e3 = new QPushButton("W");
    e3->setFixedHeight(500);
    e3->setFixedWidth(100);
    e3->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *e3short = new QShortcut(QKeySequence(Qt::Key_W), e3);
    QObject::connect(e3, SIGNAL(clicked()), this, SLOT(playe3()));
    QObject::connect(e3short, SIGNAL(activated()), e3, SLOT(animateClick()));

    QPushButton* f3 = new QPushButton("E");
    f3->setFixedHeight(500);
    f3->setFixedWidth(100);
    f3->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *f3short = new QShortcut(QKeySequence(Qt::Key_E), f3);
    QObject::connect(f3, SIGNAL(clicked()), this, SLOT(playf3()));
    QObject::connect(f3short, SIGNAL(activated()), f3, SLOT(animateClick()));

    QPushButton* g3 = new QPushButton("R");
    g3->setFixedHeight(500);
    g3->setFixedWidth(100);
    g3->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *g3short = new QShortcut(QKeySequence(Qt::Key_R), g3);
    QObject::connect(g3, SIGNAL(clicked()), this, SLOT(playg3()));
    QObject::connect(g3short, SIGNAL(activated()), g3, SLOT(animateClick()));

    QPushButton* a4 = new QPushButton("T");
    a4->setFixedHeight(500);
    a4->setFixedWidth(100);
    a4->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *a4short = new QShortcut(QKeySequence(Qt::Key_T), a4);
    QObject::connect(a4, SIGNAL(clicked()), this, SLOT(playa4()));
    QObject::connect(a4short, SIGNAL(activated()), a4, SLOT(animateClick()));

    QPushButton* b4 = new QPushButton("V");
    b4->setFixedHeight(500);
    b4->setFixedWidth(100);
    b4->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *b4short = new QShortcut(QKeySequence(Qt::Key_V), b4);
    QObject::connect(b4, SIGNAL(clicked()), this, SLOT(playb4()));
    QObject::connect(b4short, SIGNAL(activated()), b4, SLOT(animateClick()));

    QPushButton* c4 = new QPushButton("B");
    c4->setFixedHeight(500);
    c4->setFixedWidth(100);
    c4->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *c4short = new QShortcut(QKeySequence(Qt::Key_B), a4);
    QObject::connect(c4, SIGNAL(clicked()), this, SLOT(playc4()));
    QObject::connect(c4short, SIGNAL(activated()), c4, SLOT(animateClick()));

    QPushButton* d4 = new QPushButton("Y");
    d4->setFixedHeight(500);
    d4->setFixedWidth(100);
    d4->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *d4short = new QShortcut(QKeySequence(Qt::Key_Y), d4);
    QObject::connect(d4, SIGNAL(clicked()), this, SLOT(playd4()));
    QObject::connect(d4short, SIGNAL(activated()), d4, SLOT(animateClick()));

    QPushButton* e4 = new QPushButton("U");
    e4->setFixedHeight(500);
    e4->setFixedWidth(100);
    e4->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *e4short = new QShortcut(QKeySequence(Qt::Key_U), e4);
    QObject::connect(e4, SIGNAL(clicked()), this, SLOT(playe4()));
    QObject::connect(e4short, SIGNAL(activated()), e4, SLOT(animateClick()));

    QPushButton* f4 = new QPushButton("I");
    f4->setFixedHeight(500);
    f4->setFixedWidth(100);
    f4->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *f4short = new QShortcut(QKeySequence(Qt::Key_I), f4);
    QObject::connect(f4, SIGNAL(clicked()), this, SLOT(playf4()));
    QObject::connect(f4short, SIGNAL(activated()), f4, SLOT(animateClick()));

    QPushButton* g4 = new QPushButton("O");
    g4->setFixedHeight(500);
    g4->setFixedWidth(100);
    g4->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *g4short = new QShortcut(QKeySequence(Qt::Key_O), g4);
    QObject::connect(g4, SIGNAL(clicked()), this, SLOT(playg4()));
    QObject::connect(g4short, SIGNAL(activated()), g4, SLOT(animateClick()));

    QPushButton* a5 = new QPushButton("P");
    a5->setFixedHeight(500);
    a5->setFixedWidth(100);
    a5->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *a5short = new QShortcut(QKeySequence(Qt::Key_P), a5);
    QObject::connect(a5, SIGNAL(clicked()), this, SLOT(playa5()));
    QObject::connect(a5short, SIGNAL(activated()), a5, SLOT(animateClick()));

    QPushButton* b5 = new QPushButton("L");
    b5->setFixedHeight(500);
    b5->setFixedWidth(100);
    b5->setStyleSheet("QPushButton{background-color: white; font:20pt; font-weight: bold; border: 2px solid black; border-radius: 15px; text-align:bottom;}");
    QShortcut *b5short = new QShortcut(QKeySequence(Qt::Key_L), b5);
    QObject::connect(b5, SIGNAL(clicked()), this, SLOT(playb5()));
    QObject::connect(b5short, SIGNAL(activated()), b5, SLOT(animateClick()));

    //whitepiano layout draws the piano on the screen
    whitepiano->addWidget(c3);
    whitepiano->addWidget(d3);
    whitepiano->addWidget(e3);
    whitepiano->addWidget(f3);
    whitepiano->addWidget(g3);
    whitepiano->addWidget(a4);
    whitepiano->addWidget(b4);
    whitepiano->addWidget(c4);
    whitepiano->addWidget(d4);
    whitepiano->addWidget(e4);
    whitepiano->addWidget(f4);
    whitepiano->addWidget(g4);
    whitepiano->addWidget(a5);
    whitepiano->addWidget(b5);
    whitepiano->setSpacing(0);

    /*
    QPushButton black0-black9 and black0_-black9_ create buttons that are set as childs to corresponding c3-b5 keys to create the black keys on piano
    QShortCut black0short-black9short create keyboard shortcuts that connect numbers on the keyboard to buttons
    */
    QPushButton* black1 = new QPushButton("");
    black1->setFixedHeight(275);
    black1->setFixedWidth(30);
    black1->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black1->move(70,0);
    black1->setParent(c3);
    QShortcut *black1short = new QShortcut(QKeySequence(Qt::Key_1), black1);
    QObject::connect(black1, SIGNAL(clicked()), this, SLOT(black1()));
    QObject::connect(black1short, SIGNAL(activated()), black1, SLOT(animateClick()));
    QPushButton* black1_ = new QPushButton("1");
    black1_->setFixedHeight(275);
    black1_->setFixedWidth(30);
    black1_->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black1_->setParent(d3);
    QObject::connect(black1_, SIGNAL(clicked()), this, SLOT(black1()));

    QPushButton* black2 = new QPushButton("");
    black2->setFixedHeight(275);
    black2->setFixedWidth(30);
    black2->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black2->move(70,0);
    black2->setParent(d3);
    QShortcut *black2short = new QShortcut(QKeySequence(Qt::Key_2), black2);
    QObject::connect(black2, SIGNAL(clicked()), this, SLOT(black2()));
    QObject::connect(black2short, SIGNAL(activated()), black2, SLOT(animateClick()));
    QPushButton* black2_ = new QPushButton("2");
    black2_->setFixedHeight(275);
    black2_->setFixedWidth(30);
    black2_->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black2_->setParent(e3);
    QObject::connect(black2_, SIGNAL(clicked()), this, SLOT(black2()));

    QPushButton* black3 = new QPushButton("");
    black3->setFixedHeight(275);
    black3->setFixedWidth(30);
    black3->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black3->move(70,0);
    black3->setParent(f3);
    QShortcut *black3short = new QShortcut(QKeySequence(Qt::Key_3), black3);
    QObject::connect(black3, SIGNAL(clicked()), this, SLOT(black3()));
    QObject::connect(black3short, SIGNAL(activated()), black3, SLOT(animateClick()));
    QPushButton* black3_ = new QPushButton("3");
    black3_->setFixedHeight(275);
    black3_->setFixedWidth(30);
    black3_->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black3_->setParent(g3);
    QObject::connect(black3_, SIGNAL(clicked()), this, SLOT(black3()));

    QPushButton* black4 = new QPushButton("");
    black4->setFixedHeight(275);
    black4->setFixedWidth(30);
    black4->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black4->move(70,0);
    black4->setParent(g3);
    QShortcut *black4short = new QShortcut(QKeySequence(Qt::Key_4), black4);
    QObject::connect(black4, SIGNAL(clicked()), this, SLOT(black4()));
    QObject::connect(black4short, SIGNAL(activated()), black4, SLOT(animateClick()));
    QPushButton* black4_ = new QPushButton("4");
    black4_->setFixedHeight(275);
    black4_->setFixedWidth(30);
    black4_->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black4_->setParent(a4);
    QObject::connect(black4_, SIGNAL(clicked()), this, SLOT(black4()));

    QPushButton* black5 = new QPushButton();
    black5->setFixedHeight(275);
    black5->setFixedWidth(30);
    black5->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black5->move(70,0);
    black5->setParent(a4);
    QShortcut *black5short = new QShortcut(QKeySequence(Qt::Key_5), black5);
    QObject::connect(black5, SIGNAL(clicked()), this, SLOT(black5()));
    QObject::connect(black5short, SIGNAL(activated()), black5, SLOT(animateClick()));
    QPushButton* black5_ = new QPushButton("5");
    black5_->setFixedHeight(275);
    black5_->setFixedWidth(30);
    black5_->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black5_->setParent(b4);
    QObject::connect(black5_, SIGNAL(clicked()), this, SLOT(black5()));

    QPushButton* black6 = new QPushButton();
    black6->setFixedHeight(275);
    black6->setFixedWidth(30);
    black6->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black6->move(70,0);
    black6->setParent(c4);
    QShortcut *black6short = new QShortcut(QKeySequence(Qt::Key_6), black6);
    QObject::connect(black6, SIGNAL(clicked()), this, SLOT(black6()));
    QObject::connect(black6short, SIGNAL(activated()), black6, SLOT(animateClick()));
    QPushButton* black6_ = new QPushButton("6");
    black6_->setFixedHeight(275);
    black6_->setFixedWidth(30);
    black6_->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black6_->setParent(d4);
    QObject::connect(black6_, SIGNAL(clicked()), this, SLOT(black6()));

    QPushButton* black7 = new QPushButton();
    black7->setFixedHeight(275);
    black7->setFixedWidth(30);
    black7->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black7->move(70,0);
    black7->setParent(d4);
    QShortcut *black7short = new QShortcut(QKeySequence(Qt::Key_7), black7);
    QObject::connect(black7, SIGNAL(clicked()), this, SLOT(black7()));
    QObject::connect(black7short, SIGNAL(activated()), black7, SLOT(animateClick()));
    QPushButton* black7_ = new QPushButton("7");
    black7_->setFixedHeight(275);
    black7_->setFixedWidth(30);
    black7_->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black7_->setParent(e4);
    QObject::connect(black7_, SIGNAL(clicked()), this, SLOT(black7()));

    QPushButton* black8 = new QPushButton();
    black8->setFixedHeight(275);
    black8->setFixedWidth(30);
    black8->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black8->move(70,0);
    black8->setParent(f4);
    QShortcut *black8short = new QShortcut(QKeySequence(Qt::Key_8), black8);
    QObject::connect(black8, SIGNAL(clicked()), this, SLOT(black8()));
    QObject::connect(black8short, SIGNAL(activated()), black8, SLOT(animateClick()));
    QPushButton* black8_ = new QPushButton("8");
    black8_->setFixedHeight(275);
    black8_->setFixedWidth(30);
    black8_->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black8_->setParent(g4);
    QObject::connect(black8_, SIGNAL(clicked()), this, SLOT(black8()));

    QPushButton* black9 = new QPushButton();
    black9->setFixedHeight(275);
    black9->setFixedWidth(30);
    black9->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black9->move(70,0);
    black9->setParent(g4);
    QShortcut *black9short = new QShortcut(QKeySequence(Qt::Key_9), black9);
    QObject::connect(black9, SIGNAL(clicked()), this, SLOT(black9()));
    QObject::connect(black9short, SIGNAL(activated()), black9, SLOT(animateClick()));
    QPushButton* black9_ = new QPushButton("9");
    black9_->setFixedHeight(275);
    black9_->setFixedWidth(30);
    black9_->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black9_->setParent(a5);
    QObject::connect(black9_, SIGNAL(clicked()), this, SLOT(black9()));

    QPushButton* black0 = new QPushButton();
    black0->setFixedHeight(275);
    black0->setFixedWidth(30);
    black0->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black0->move(70,0);
    black0->setParent(a5);
    QShortcut *black0short = new QShortcut(QKeySequence(Qt::Key_0), black0);
    QObject::connect(black0, SIGNAL(clicked()), this, SLOT(black0()));
    QObject::connect(black0short, SIGNAL(activated()), black0, SLOT(animateClick()));
    QPushButton* black0_ = new QPushButton("0");
    black0_->setFixedHeight(275);
    black0_->setFixedWidth(30);
    black0_->setStyleSheet("QPushButton{background-color: black; color:white; border-radius: 0px;}");
    black0_->setParent(b5);
    QObject::connect(black0_, SIGNAL(clicked()), this, SLOT(black0()));

    QPushButton* question = new QPushButton(" Choose a song!");
    question->setStyleSheet("QPushButton {color: white; font: 12pt; font-weight: bold; background-color: darkblue; border-radius: 5px;}");
    question->setFixedWidth(200);
    question->setFixedHeight(40);
    QPushButton* blank = new QPushButton();
    blank->setStyleSheet("QPushButton {border: none}");
    blank->setFixedWidth(1200);

    QWidgetAction* option = new QWidgetAction(this);
    QLabel *op = new QLabel(tr("Freestyle"));
    op->setAlignment(Qt::AlignCenter);
    op->setStyleSheet("QLabel {color : darkblue; font: 10pt; font-weight: bold;}");
    option->setDefaultWidget(op);
    connect(option,SIGNAL(triggered()),this,SLOT(freestyle()));

    QWidgetAction* option1 = new QWidgetAction(this);
    QLabel *op1 = new QLabel(tr("Yankee Doodle"));
    op1->setAlignment(Qt::AlignCenter);
    op1->setStyleSheet("QLabel {color : darkblue; font: 10pt; font-weight: bold;}");
    option1->setDefaultWidget(op1);
    connect(option1,SIGNAL(triggered()),this,SLOT(yankee()));

    QWidgetAction* option2 = new QWidgetAction(this);
    QLabel *op2 = new QLabel(tr("Itsy Bitsy Spider"));
    op2->setAlignment(Qt::AlignCenter);
    op2->setStyleSheet("QLabel {color : darkblue; font: 10pt; font-weight: bold;}");
    option2->setDefaultWidget(op2);
    connect(option2,SIGNAL(triggered()),this,SLOT(itsy()));

    QWidgetAction* option3 = new QWidgetAction(this);
    QLabel *op3 = new QLabel(tr("Row Row Row Your Boat"));
    op3->setAlignment(Qt::AlignCenter);
    op3->setStyleSheet("QLabel {color : darkblue; font: 10pt; font-weight: bold;}");
    option3->setDefaultWidget(op3);
    connect(option3,SIGNAL(triggered()),this,SLOT(row()));

    QWidgetAction* option4 = new QWidgetAction(this);
    QLabel *op4 = new QLabel(tr("I Love You (Barney)"));
    op4->setAlignment(Qt::AlignCenter);
    op4->setStyleSheet("QLabel {color : darkblue; font: 10pt; font-weight: bold;}");
    option4->setDefaultWidget(op4);
    connect(option4,SIGNAL(triggered()),this,SLOT(barney()));

    QWidgetAction* option5 = new QWidgetAction(this);
    QLabel *op5 = new QLabel(tr("Mary Had a Little Lamb"));
    op5->setAlignment(Qt::AlignCenter);
    op5->setStyleSheet("QLabel {color : darkblue; font: 10pt; font-weight: bold;}");
    option5->setDefaultWidget(op5);
    connect(option5,SIGNAL(triggered()),this,SLOT(mary()));

    QMenu* menu   = new QMenu();
    menu->addAction(option);
    menu->addSeparator();
    menu->addAction(option1);
    menu->addSeparator();
    menu->addAction(option2);
    menu->addSeparator();
    menu->addAction(option3);
    menu->addSeparator();
    menu->addAction(option4);
    menu->addSeparator();
    menu->addAction(option5);
    question->setMenu(menu); //assigns menu to question button to create a dropdown menu

    QHBoxLayout* songs = new QHBoxLayout;
    songs->addWidget(blank);
    songs->addWidget(question);
    songswithnotes->addLayout(songs);
    songswithnotes->addWidget(notes);

    QHBoxLayout* testing = new QHBoxLayout;
    testing->addWidget(hints);
    endlayout -> addLayout(perlay);
    endlayout -> addLayout(songswithnotes);
    endlayout -> addLayout(whitepiano);
    endlayout -> addLayout(testing);
    this->setLayout(endlayout);
}

void perfectpiano::backhome() {
    MainWindow* m = new MainWindow;
    m->show();
    this->hide();
}

void perfectpiano::help()
{
    QLabel* help = new QLabel("To play a song, choose a song from the list!                                               Play the notes by pressing the corresponding keys on your keyboard! Close this window when you're ready to play.");
    help->setWordWrap(true);
    help->setFixedWidth(650);
    help->setAlignment(Qt::AlignHCenter);
    help->setStyleSheet("QLabel{font:10pt; color: darkred; background-color:pink}");
    help->show();
}

void perfectpiano::showhints()
{
    hints->setText("C      D      E      F      G      A      B      C      D      E      F      G      A      B");
    hints->setStyleSheet("QLabel{font: 20pt; font-weight:bold}");
    hints->setAlignment(Qt::AlignBottom);
    hints->setAlignment(Qt::AlignCenter);
}

void perfectpiano::hidehints()
{
    hints->setText("");
}

void perfectpiano::freestyle()
{
    notes->setText("");
}


void perfectpiano::yankee()
{
    notes->setText("C C D E C E D   G C C D E C B   G C C D E F E D   C B G A B C C   A B A G A B C   G A G F E G   A B A G A B C   A G C B D C C                                           B B Y U B U Y   R B B Y U B V   R B B Y U I U Y   B V R T V B B   T V T R T V B   R T R E W R   T V T R T V B   T R B V Y B B");
    notes->setWordWrap(true);
    notes->setStyleSheet("QLabel {color: darkblue; font: 10pt; font-weight: bold; border-radius: 5px;}");
    notes->setAlignment(Qt::AlignCenter);
}

void perfectpiano::itsy()
{
    notes->setText("G C C C D E E   E D C D E C   E E F G   G F E F G E   C C D E   E D C D E C   G G C C C D E E   E D C D E C                                                                                                    R B B B Y U U   U Y B Y U B   U U I O   O I U I O U   B B Y U   U Y B Y U B   R R B B B Y U U   U Y B Y U B");
    notes->setWordWrap(true);
    notes->setStyleSheet("QLabel {color: darkblue; font: 10pt; font-weight: bold; border-radius: 5px;}");
    notes->setAlignment(Qt::AlignCenter);
}

void perfectpiano::row()
{
    notes->setText("D D D E F#   F# E F# G A   D D D A A A F# F# F# D D D   A G F# E D                                                                                                                                                                                 Q Q Q W 3   3 W 3 R T   Y Y Y T T T 3 3 3 Q Q Q   T R 3 W Q");
    notes->setWordWrap(true);
    notes->setStyleSheet("QLabel {color: darkblue; font: 10pt; font-weight: bold; border-radius: 5px;}");
    notes->setAlignment(Qt::AlignCenter);
}

void perfectpiano::barney()
{
    notes->setText("G E G G E G   A G F E D E F   E F G C C C C C D E F G   G D D F E D C   G E G G E G   A G F E D E F   E F G C C C C C D E F G   G D D F E D C                                           O U O O U O   P O I U Y U I   U I O B B B B B Y U I O   O Y Y I U Y B   O U O O U O   P O I U Y U I   U I O B B B B B Y U I O   O Y Y I U Y B");
    notes->setWordWrap(true);
    notes->setStyleSheet("QLabel {color: darkblue; font: 10pt; font-weight: bold; border-radius: 5px;}");
    notes->setAlignment(Qt::AlignCenter);
}

void perfectpiano::mary()
{
    notes->setText("E D C D E E E   D D D E G G   E D C D E E E   E D D E D   E D C D E E E   D D D E G G   E D C D E E E   E D D E D                                                       U Y B Y U U U   Y Y Y U O O   U Y B Y U U U   U Y Y U Y   U Y B Y U U U   Y Y Y U O O   U Y B Y U U U   U Y Y U Y");
    notes->setWordWrap(true);
    notes->setStyleSheet("QLabel {color: darkblue; font: 10pt; font-weight: bold; border-radius: 5px;}");
    notes->setAlignment(Qt::AlignCenter);
}

void perfectpiano::playc3()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/c3.mp3"));
    p->setVolume(1000);
    p->play();
}

void perfectpiano::playd3()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/d3.mp3"));
    p->setVolume(1000);
    p->play();
}

void perfectpiano::playe3()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/e3.mp3"));
    p->setVolume(1000);
    p->play();
}

void perfectpiano::playf3()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/f3.mp3"));
    p->setVolume(1000);
    p->play();
}

void perfectpiano::playg3()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/g3.mp3"));
    p->setVolume(1000);
    p->play();
}

void perfectpiano::playa4()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/a4.mp3"));
    p->setVolume(1000);
    p->play();
}

void perfectpiano::playb4()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/b4.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::playc4()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/c4.mp3"));
    p->setVolume(1000);
    p->play();
}

void perfectpiano::playd4()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/d4.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::playe4()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/e4.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::playf4()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/f4.mp3"));
    p->setVolume(1000);
    p->play();
}

void perfectpiano::playg4()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/g4.mp3"));
    p->setVolume(1000);
    p->play();
}

void perfectpiano::playa5()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/a5.mp3"));
    p->setVolume(1000);
    p->play();
}

void perfectpiano::playb5()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/b5.mp3"));
    p->setVolume(1000);
    p->play();
}

void perfectpiano::black1()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/black1.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::black2()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/black2.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::black3()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/black3.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::black4()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/black4.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::black5()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/black5.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::black6()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/black6.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::black7()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/black7.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::black8()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/black8.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::black9()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/black9.mp3"));
    p->setVolume(1000);
    p->play();
}
void perfectpiano::black0()
{
    QMediaPlayer* p = new QMediaPlayer();
    p->setMedia(QUrl("qrc:/black0.mp3"));
    p->setVolume(1000);
    p->play();
}

