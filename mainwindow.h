#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSize>
#include <QIcon>
#include <QSize>
#include <QFontDatabase>
#include <QMovie>
#include <QPixmap>
#include <QMediaPlayer>
#include <QApplication>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void buttonpressed1();
    void buttonpressed2();
    void buttonpressed3();
    void buttonpressed4();
    void directionspressed();

    void backhome()
    {
        MainWindow* temp = new MainWindow;
        temp->show();
    }
};
#endif // MAINWINDOW_H
