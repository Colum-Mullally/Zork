#ifndef OUTSIDEGEN_H
#define OUTSIDEGEN_H

#include <QWidget>
#include <QGridLayout>
#include "House.h"
#include <QPainter>
#include <QPoint>
#include <QPen>
class outsideGen : public QWidget
{
    Q_OBJECT
public:
    outsideGen(House *rm, QWidget *parent=0);
    void changeHouse( House* rm);
    void HouseFire(House *h);
private:
      QPixmap FireB;
      QPixmap FireC;
      QPixmap FireE;
      QPixmap FireG;
      QPixmap FireH;
      QPixmap FireI;
      QRect backgroundRect;
protected:
    House *rm;
    void paintEvent(QPaintEvent *e);
signals:

public slots:
};

#endif // OUTSIDEGEN_H
