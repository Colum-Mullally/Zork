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
public:
    Room(string x): Space(x){}
    void addItem(Item *inItem);
    string displayItem();
        int numberOfItems();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    string longDescription() override;
};
#endif
