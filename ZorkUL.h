#ifndef ZORKUL_H_
#define ZORKUL_H_
#include "Space.h"
#include "House.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::vector;

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
    vector<vector<Space*>> WorldMap;
    string goRoom(Space *next);
};

#endif /*ZORKUL_H_*/
