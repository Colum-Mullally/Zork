#ifndef OUTSIDEGEN_H
#define OUTSIDEGEN_H

#include <QWidget>
#include <QGridLayout>
#include "House.h"
class outsideGen : public QWidget
{
    Q_OBJECT
public:
    outsideGen(House *rm, QWidget *parent=0);
protected:
    House *rm;
    void paintEvent(QPaintEvent *e);
signals:

public slots:
};

#endif // OUTSIDEGEN_H
