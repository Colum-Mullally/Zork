#ifndef MapGen_H
#define MapGen_H

#include <QWidget>
#include <QGridLayout>

#include "Room.h"
#include "space.h"

namespace Ui {
class MapGen;
}

class MapGen : public QWidget
{
    Q_OBJECT

public:
    explicit MapGen(int x, int y,  Room** houseLayout, QWidget *parent = 0 );
    ~MapGen();
    void changeRooms(int x, int y, Room** houseLayout);

protected:
    void paintEvent(QPaintEvent *e);
private:
    //Ui::MapGen *ui;
    QGridLayout *mainGrid;
    Room** rooms[3];
    //void createRooms(Room *rooms[9], RoomPainter *paintedRooms[9]);
};

#endif // MapGen_H
