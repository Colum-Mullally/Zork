#ifndef ZORKUL_H_
#define ZORKUL_H_
#include "Room.h"
#include<House.h>
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Space *currentSpace;
	void createRooms();
	void printWelcome();
    void printHelp();

    void createItems();
    void displayItems();



public:
    House *a, *b, *c, *d, *e, *f, *g, *h, *i;
    ZorkUL();
    vector<Item> inventory;
    void play();
    string go(string direction);


};

#endif /*ZORKUL_H_*/
