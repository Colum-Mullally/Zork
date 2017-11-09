#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "qmediaplayer.h"

using namespace std;
using std::vector;

class Item {
private:
    string description;
    bool holdable;
    int mod;

public:
    Item (string inDescription, bool inholdable, int mod);
	string getShortDescription();
    string getLongDescription();
    int getMod();
    bool getHold();
    ~Item();
};

#endif /*ITEM_H_*/
