#ifndef ZORKUL_H_
#define ZORKUL_H_
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
using namespace std;

class ZorkUL: public QObject,public QGraphicsRectItem {
      Q_OBJECT
private:
    Space *currentSpace;
	void createRooms();
	void printWelcome();
    void printHelp();

    void createItems();
    void displayItems();


public:
   explicit ZorkUL(QGraphicsItem * parent=0);
    void play();
    string go(string direction);


};

#endif /*ZORKUL_H_*/
