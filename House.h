#ifndef House_H
#define House_H

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class House {

private:
    string description;
    map<string, House*> exits;
    string exitString();


public:
    int numberOfItems();
    House(string description);
    void setExits(House *north, House *east, House *south, House *west);
    string shortDescription();
    string longDescription();
    House* nextHouse(string direction);
};

#endif // House_H
