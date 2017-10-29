#ifndef ZORKUL_H_
#define ZORKUL_H_
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
	Room *currentRoom;
	void createRooms();
	void printWelcome();
    void printHelp();

    void createItems();
    void displayItems();


public:
	ZorkUL();
    void play();
    string goRoom(string direction);
    vector<Item*> inventory;


};

#endif /*ZORKUL_H_*/
