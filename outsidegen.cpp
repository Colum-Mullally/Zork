#include "outsidegen.h"



outsideGen::outsideGen(House*  rm ,QWidget *parent) : QWidget(parent)
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
   QPixmap FireB(":/resource/ROOMS/FireB.png");
   QPixmap FireC(":/resource/ROOMS/FireC.png");
   QPixmap FireE(":/resource/ROOMS/FireE.png");
   QPixmap FireG(":/resource/ROOMS/FireG.png");
   QPixmap FireH(":/resource/ROOMS/FireH.png");
   QPixmap FireI(":/resource/ROOMS/FireI.png");
    this->FireB=FireB;
    this->FireC=FireC;
    this->FireE=FireE;
    this->FireG=FireG;
    this->FireH=FireH;
    this->FireI=FireI;

  int squareSize = rect().width() < rect().height() ? rect().width() : rect().height();
  backgroundRect = QRect(0,0,squareSize,squareSize);
    if(rm->shortDescription()=="a")
     painter.drawPixmap(backgroundRect, outsideA);
    else if(rm->shortDescription()=="f")
        painter.drawPixmap(backgroundRect, outsideF);
    else if(rm->shortDescription()=="d")
        painter.drawPixmap(backgroundRect, outsideD);

}
void outsideGen::HouseFire(House* h){
     QPainter painter( this );
    if(h->shortDescription()=="b"){
         painter.drawPixmap(backgroundRect, FireB);
    }
    else if(h->shortDescription()=="c"){
           painter.drawPixmap(backgroundRect, FireC);
    }
    else if(h->shortDescription()=="e"){
            painter.drawPixmap(backgroundRect, FireE);
    }
   else if(h->shortDescription()=="g"){
        painter.drawPixmap(backgroundRect, FireG);
    }
    else if(h->shortDescription()=="i"){
        painter.drawPixmap(backgroundRect, FireI);
    }
    else if(h->shortDescription()=="h"){
        painter.drawPixmap(backgroundRect, FireH);
    }
}
