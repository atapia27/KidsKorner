#ifndef CRAZYCAB_H
#define CRAZYCAB_H

#include <QWidget>

class crazycab : public QWidget
{
    Q_OBJECT
public:
    explicit crazycab(QWidget *parent = nullptr);

public slots:
    void backhome();

};

#endif // CRAZYCAB_H
