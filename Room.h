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
public:
    Room(string x);
    string longDescription() override;
    void setX(int x2);
    void setY(int y2);
    int getY();
    int getX();
};
#endif
