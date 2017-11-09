#include "MapGen.h"

#include <QPainter>
#include <QPoint>
#include <QPen>

MapGen::MapGen(int x, int y, Room** (*rm), QWidget *parent) :
    QWidget(parent)
{
    changeRooms(x, y, rm);
    outsideb = true;
}

void MapGen::changeRooms(int x, int y, Room** *rm)
{
    outsideb = false;

    rooms.clear();
    rooms.resize(3);
    for (int i=0; i<3; i++)
    {
        rooms[i].resize(3, NULL);
    }
    rooms[1][1] = rm[x][y];
    if(x > 0){
        rooms[0][1] = rm[x-1][y];
    }
    if(x < 4){
        rooms[2][1] = rm[x+1][y];
    }
    if(y > 0){
        rooms[1][0] = rm[x][y-1];
    }
    if(y < 4){
        rooms[1][2] = rm[x][y+1];
    }
    this->update();

}

MapGen::~MapGen()
{
    delete mainGrid;
}

void MapGen::paintEvent(QPaintEvent *e)
{

    this->setHidden(false);
    QPainter painter( this );
     QPixmap room(":/resource/ROOMS/Room.png");
     QPixmap south(":/resource/ROOMS/south.png");
     QPixmap west(":/resource/ROOMS/west.png");
   QPixmap north(":/resource/ROOMS/north.png");
   QPixmap east(":/resource/ROOMS/east.png");
   QPixmap fire(":/resource/ROOMS/RoomFire.png");
   QPixmap Player(":/resource/ROOMS/player.png");
    painter.setRenderHint( QPainter::Antialiasing, true );
    painter.setPen( QPen( Qt::black, 2 ) );

    int squareSize = rect().width() < rect().height() ? rect().width() : rect().height();
    int nrOfRooms = 3;

    int rowOffset, colOffset;
    int roomLength = ((squareSize - ((squareSize / 9)))/nrOfRooms);
        for (int row = 0; row < 3; row++)
        {
            rowOffset = (roomLength * row) + (squareSize / 9);
            for (int col = 0; col < 3; col++)
            {
                if (rooms[row][col] != NULL)
                {

                    colOffset = roomLength * col + (squareSize / 9);
                    QPoint p[4] = {
                        QPoint(0 + colOffset, 0 + rowOffset),
                        QPoint(roomLength + colOffset, 0 + rowOffset), //northeast
                        QPoint(roomLength + colOffset, roomLength + rowOffset), //southeast
                        QPoint(0 + colOffset, roomLength + rowOffset) //southwest
                    };
                  if(rooms[row][col]->getFire()){
                       painter.drawPixmap(p[0],fire);
                    }
                  else
                  painter.drawPixmap(p[0],room);

                    if (row == 1 && col == 1)
                    {
                       painter.drawPixmap(p[0],Player);
                    }


                    int doorPos;
                    if (rooms[row][col]->CheckExit("north"))
                    {
                        doorPos = p[0].x() + (roomLength / 6);
                        QPoint leftDoor = QPoint(doorPos, 0 + rowOffset);
                        QPoint rightDoor = QPoint(doorPos + (roomLength / 6), 0 + rowOffset);

                        painter.drawPixmap(p[0],north);
                    }
                    //draw southern wall and door if necessary
                    if (rooms[row][col]->CheckExit("south"))
                    {
                        painter.drawPixmap(p[0],south);

                    }
                    //draw western wall and door if necessary
                    if (rooms[row][col]->CheckExit("west"))
                    {
                        painter.drawPixmap(p[0],west);

                    }

                    if (rooms[row][col]->CheckExit("east"))
                    {
                        painter.drawPixmap(p[0],east);

                    }


                }
            }
        }
}

void MapGen::outside(){
    rooms.clear();
    rooms.resize(3);
    for (int i=0; i<3; i++)
    {
        rooms[i].resize(3, NULL);
    }
    this->update();
}
