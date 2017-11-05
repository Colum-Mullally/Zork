#ifndef Room_H
#define Room_H
#include "space.h"
#include "item.h"
// Derived class
class Room: public Space
{
protected:
    string exitString() override;
    vector <Item> itemsInRoom;
    int x1;
    int y;
public:
    Room(string x);
    void addItem(Item *inItem);
    string displayItem();
        int numberOfItems();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    string longDescription() override;
    void setX(int x2);
    void setY(int y2);
    int getY();
    int getX();
};
#endif
