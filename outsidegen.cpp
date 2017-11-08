#include "outsidegen.h"
#include <QPainter>
#include <QPoint>
#include <QPen>


outsideGen::outsideGen(House *  rm ,QWidget *parent) : QWidget(parent)
{
    this->rm=rm;
     this->update();
}
void outsideGen::paintEvent(QPaintEvent *e){
     QPainter painter( this );
     painter.setRenderHint( QPainter::Antialiasing, true );
     painter.setPen( QPen( Qt::black, 2 ) );
  QPixmap outside(":/resource/ROOMS/Outsidemap.png");
  int squareSize = rect().width() < rect().height() ? rect().width() : rect().height();
  QRect backgroundRect = QRect(0,0,squareSize,squareSize);
  painter.drawPixmap(backgroundRect, outside);
}
