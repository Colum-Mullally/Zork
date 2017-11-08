#include "outsidegen.h"
#include <QPainter>
#include <QPoint>
#include <QPen>


outsideGen::outsideGen(House *  rm ,QWidget *parent) : QWidget(parent)
{
    this->rm=rm;
     this->update();
}
void outsideGen::changeHouse(House* rm){
    this->rm=rm;
    this->update();
}
void outsideGen::paintEvent(QPaintEvent *e){
     QPainter painter( this );
  QPixmap outsideA(":/resource/ROOMS/OutsideA.png");
  QPixmap outsideF(":/resource/ROOMS/OutsideF.png");
  QPixmap outsideD(":/resource/ROOMS/OutsideD.png");
  int squareSize = rect().width() < rect().height() ? rect().width() : rect().height();
  QRect backgroundRect = QRect(0,0,squareSize,squareSize);
    if(rm->shortDescription()=="a")
     painter.drawPixmap(backgroundRect, outsideA);
    else if(rm->shortDescription()=="f")
        painter.drawPixmap(backgroundRect, outsideF);
    else if(rm->shortDescription()=="d")
        painter.drawPixmap(backgroundRect, outsideD);

}
