#ifndef ZORKUL_H_
#define ZORKUL_H_
#include "Room.h"
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
    ZorkUL();
    void play();
    string go(string direction);


};

#endif /*ZORKUL_H_*/
