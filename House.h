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
    void SetRoomExits(Room **RoomMap);

private:
    RandomRoomGenerator(int rId);
};

#endif // House_H
