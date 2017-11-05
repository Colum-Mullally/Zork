#ifndef MapGen_H
#define MapGen_H

#include <QWidget>
#include <QGridLayout>

#include "GameData\ZorkUL.h"

namespace Ui {
class MapGen;
}

class MapGen : public QWidget
{
    Q_OBJECT

public:
    explicit MapGen(QWidget *parent = 0 );
    ~MapGen();
    void changeRooms();

protected:
    void paintEvent(QPaintEvent *e);
private:
    //Ui::MapGen *ui;
    QGridLayout *mainGrid;
    vector<vector<Room*>> rooms;
    int visibilityRange;
    //void createRooms(Room *rooms[9], RoomPainter *paintedRooms[9]);
};

#endif // MapGen_H
