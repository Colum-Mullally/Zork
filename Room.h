#ifndef Room_H
#define Room_H
#include "space.h"
// Derived class
class Room: public Space
{
protected:
    string exitString() override;
    int x1;
    int y;
    bool fire;
public:
    Room(string x, int type);
    string longDescription() override;
    void setX(int x2);
    void setY(int y2);
    int getY();
    int getX();
};
#endif
