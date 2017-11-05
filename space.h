#ifndef Space_H
#define Space_H
#include <map>
#include <string>
#include <vector>
#include "item.h"

using namespace std;
using std::vector;

class Space{
protected:
        vector <Item> itemsInRoom;
    map<string, Space*> exits;
    virtual string exitString();
    string description;



public:
    explicit Space(string description);
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
    int setY(int y1);
    int getX();
    int getY();
    int setX(int x1);
};
#endif
