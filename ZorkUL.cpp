#include <iostream>
#include<House.h>
using namespace std;
#include "ZorkUL.h"
#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();

}

ZorkUL::ZorkUL(QGraphicsItem *parent) :QGraphicsRectItem(parent) {
	createRooms();
}

void ZorkUL::createRooms()  {
 House *a, *b, *c, *d, *e, *f, *g, *h, *i;

    a = new House("a");
 cout<<"here";
   // scene()->addItem(a);
    //b = new House("b");
   // c = new House("c");
   // d = new House("d");
   // e = new House("e");
   // f = new House("f");
   // g = new House("g");
   // h = new House("h");
   // i = new House("i");
  //             (N, E, S, W)
   // a->setExits(b, d, g, NULL);
  //  b->setExits(NULL, NULL, a,NULL);
   // c->setExits(NULL, NULL, d, NULL);
   // d->setExits(c, f, h, a);
   // e->setExits(NULL, NULL, f, NULL);
   // f->setExits(e, NULL, i, d);
   // g->setExits(a, NULL, NULL, NULL);
  //  h->setExits(d, NULL, NULL, NULL);
    //i->setExits(f, NULL, NULL, NULL);
        currentSpace = a;

}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {

}

void ZorkUL::printWelcome() {
    //cout << "start"<< endl;
    //cout << "info for help"<< endl;
    //cout << endl;
    //cout << currentSpace->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */

/** COMMANDS **/
void ZorkUL::printHelp() {
    //cout << "valid inputs are; " << endl;

}

string ZorkUL::go(string direction) {
    Space* nextRoom = currentSpace->nextSpace(direction);
      currentSpace = nextRoom;
      return currentSpace->longDescription();
}
