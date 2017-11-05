#include <iostream>
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

ZorkUL::ZorkUL(){
	createRooms();
}

void ZorkUL::createRooms()  {
   int count=1;
    a = new House("a",count++);
    b = new House("b",count++);
    c = new House("c",count++);
    d = new House("d",count++);
    e = new House("e",count++);
    f = new House("f",count++);
    g = new House("g",count++);
    h = new House("h",count++);
    i = new House("i",count++);
  //             (N, E, S, W)
    a->setExits(b, d, g, NULL);
   b->setExits(NULL, NULL, a,NULL);
    c->setExits(NULL, NULL, d, NULL);
   d->setExits(c, f, h, a);
    e->setExits(NULL, NULL, f, NULL);
   f->setExits(e, NULL, i, d);
   g->setExits(a, NULL, NULL, NULL);
    h->setExits(d, NULL, NULL, NULL);
    i->setExits(f, NULL, NULL, NULL);
        currentSpace =a;

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
