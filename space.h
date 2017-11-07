#ifndef Space_H
#define Space_H
#include <map>
#include <string>
#include <vector>
#include "item.h"

using namespace std;
using std::vector;

class Space{
private:
    int x;
    int y;
    int type;
    bool fire;
    bool nextFire = false;
protected:
        vector <Item> itemsInRoom;
    virtual string exitString();
    string description;



public:
    map<string, Space*> exits;
    explicit Space(string description, int type);
    void setExits(Space *north, Space *east, Space *south, Space *west);
    Space* nextSpace(string direction);
    string shortDescription();
    virtual string longDescription();
    void addItem(Item *inItem);
     vector <Item>displayItem();
    int numberOfItems();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);


    bool CheckExit(string x);
    void setExits(Space *Dir, string d);
    void setY(int y1);
    int getX();
    int getY();
    void setX(int x1);
    int getType();
    bool getFire();
    void setFire();
    void setNextFire();
    bool getNextFire();
};
#endif
