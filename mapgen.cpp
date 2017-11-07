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
    //delete ui;
    //delete mainGrid;
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
    painter.setRenderHint( QPainter::Antialiasing, true );
    painter.setPen( QPen( Qt::black, 2 ) );

    int squareSize = rect().width() < rect().height() ? rect().width() : rect().height();
    QRect backgroundRect = QRect(0,0,squareSize,squareSize);
    painter.drawImage(backgroundRect, QImage("GameView\\pictures\\scroll.png"));
    //number of rooms in width and height, that should be printed by map
    int nrOfRooms = 3;

    int rowOffset, colOffset;
    int roomLength = ((squareSize - ((squareSize / 9)))/nrOfRooms);
        /*
       int playerPosX = p[0].x() + (roomLength / 2) - (roomLength / 12);
        int playerPosY = p[0].y() + (roomLength / 2) - (roomLength / 12);
        QRect playerRect = QRect(playerPosX, playerPosY, roomLength / 6, roomLength / 6);

        painter.setBrush( QBrush( Qt::red ) );
        painter.setPen( Qt::NoPen );
        painter.drawEllipse(playerRect);
        painter.setBrush( Qt::NoBrush );
        painter.setPen( QPen( Qt::black, 2 ) );

        painter.drawLine( p[0], p[1] );

        painter.drawLine( p[1], p[2] );

        painter.drawLine( p[1], p[0] );

        painter.drawLine( p[2], p[2] );*/

        for (int row = 0; row < 3; row++)
        {
            rowOffset = (roomLength * row) + (squareSize / 9);
            for (int col = 0; col < 3; col++)
            {
                if (rooms[row][col] != NULL)
                {

                    colOffset = roomLength * col + (squareSize / 9);
                    QPoint p[4] = {
                        QPoint(0 + colOffset, 0 + rowOffset), //northwest
                        QPoint(roomLength + colOffset, 0 + rowOffset), //northeast
                        QPoint(roomLength + colOffset, roomLength + rowOffset), //southeast
                        QPoint(0 + colOffset, roomLength + rowOffset) //southwest
                    };
                  if(rooms[row][col]->getFire()){
                       painter.drawPixmap(p[0],fire);
                    }
                  else
                  painter.drawPixmap(p[0],room);
                    //draw items
                   /* if (!rooms[row][col]->itemsInRoom.empty())
                    {
                        for(std::vector<Item>::iterator it = rooms[row][col]->itemsInRoom.begin(); it != rooms[row][col]->itemsInRoom.end(); ++it)
                        {
                            int playerPosX = p[0].x() + (roomLength / 2) - (roomLength / 12);
                            int playerPosY = p[0].y() + (roomLength / 2) - (roomLength / 12);

                            //calculate random upper left corner of item in room
                            //ten possible slots in width and height
                            int posX = p[0].x() + it->randPositionX * (roomLength/10) - (it->randPositionX / 9 * (roomLength/6));
                            int posY = p[0].y() + it->randPositionY * (roomLength/10) - (it->randPositionY / 9 * (roomLength/6));
                            if(posX > playerPosX - roomLength/6 && posX < playerPosX + roomLength/6 && posY > playerPosY - roomLength/6 && posY < playerPosY + roomLength/6)
                            {
                                posX += roomLength/3;
                                posY += roomLength/3;
                            }

                            QRect itemRect = QRect(posX, posY, roomLength /6, roomLength /6);
                            QImage itemImg = QImage(QString::fromStdString(it->getPicturePath()));
                            painter.drawImage(itemRect, itemImg);
                        }
                    }*/

                    //draw player

                    if (row == 1 && col == 1)
                    {
                        int playerPosX = p[0].x() + (roomLength / 2) - (roomLength / 12);
                        int playerPosY = p[0].y() + (roomLength / 2) - (roomLength / 12);
                        QRect playerRect = QRect(playerPosX, playerPosY, roomLength / 6, roomLength / 6);

                        painter.setBrush( QBrush( Qt::red ) );
                        painter.setPen( Qt::NoPen );
                        painter.drawEllipse(playerRect);
                        painter.setBrush( Qt::NoBrush );
                        painter.setPen( QPen( Qt::black, 2 ) );
                    }


                    int doorPos;
                    //draw northern wall and door if necessary
                    if (rooms[row][col]->CheckExit("north"))
                    {
                        doorPos = p[0].x() + (roomLength / 6);
                        QPoint leftDoor = QPoint(doorPos, 0 + rowOffset);
                        QPoint rightDoor = QPoint(doorPos + (roomLength / 6), 0 + rowOffset);
                       // painter.drawLine( p[0], leftDoor );
                       // painter.drawLine( rightDoor, p[1] );
                        painter.drawPixmap(p[0],north);
                    }
                    else
                        painter.drawLine( p[0], p[1] );

                    //draw southern wall and door if necessary
                    if (rooms[row][col]->CheckExit("south"))
                    {
                        doorPos = p[3].x() + (roomLength / 6);
                        QPoint leftDoor = QPoint(doorPos, roomLength + rowOffset);
                        QPoint rightDoor = QPoint(doorPos + (roomLength / 6), roomLength + rowOffset);
                       // painter.drawLine( p[3], leftDoor );
                       // painter.drawLine( rightDoor, p[2] );
                        painter.drawPixmap(p[0],south);

                    }
                    else
                        painter.drawLine( p[2], p[3] );

                    //draw western wall and door if necessary
                    if (rooms[row][col]->CheckExit("west"))
                    {
                        doorPos = p[0].y() + 1 * (roomLength / 6);
                        QPoint highDoor = QPoint(0 + colOffset, doorPos);
                        QPoint downDoor = QPoint(0 + colOffset, doorPos + (roomLength / 6));
                        //painter.drawLine( p[0], highDoor );
                        //painter.drawLine( downDoor, p[3] );
                        painter.drawPixmap(p[0],west);

                    }
                    else
                        //painter.drawLine( p[0], p[3] );

                    //draw eastern wall and door if necessary
                    if (rooms[row][col]->CheckExit("east"))
                    {
                        doorPos = p[1].y() + 1* (roomLength / 6);
                        QPoint highDoor = QPoint(roomLength + colOffset, doorPos);
                        QPoint downDoor = QPoint(roomLength + colOffset, doorPos + (roomLength / 6));
                        painter.drawLine( p[1], highDoor );
                        painter.drawLine( downDoor, p[2] );
                        painter.drawPixmap(p[0],east);

                    }
                    else{}
                        painter.drawLine( p[1], p[2] );

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
