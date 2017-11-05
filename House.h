#ifndef House_H
#define House_H
#include "space.h"
#include <map>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include "Room.h"
using namespace std;
using std::vector;

class House :public Space {
protected:
    string exitString() override;
public:
    House(string description,int rId);
    string longDescription() override;

    Room* GetNorthEntrance();
    Room *GetSouthEntrance();
    int getX();
    Room **RoomMap[5] ;
    int getY();
private:
    int x1;
    int y1;
    void RandomRoomGenerator(int rId);
};

#endif // House_H
