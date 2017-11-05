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
    a = new House("a",count++,0);
    b = new House("b",count++,1,a);
    d = new House("d",count++,0);
    c = new House("c",count++,2,d);
    f = new House("f",count++,0);

    e = new House("e",count++,3,f);
    g = new House("g",count++,4,a);
    h = new House("h",count++,5,d);
    i = new House("i",count++,6,f);
    a->setX(1);
    a->setY(0);
    b->setX(0);
    b->setY(0);
    c->setX(0);
    c->setY(1);
    d->setX(1);
    d->setY(1);
    e->setX(0);
    e->setY(2);
    f->setX(1);
    f->setY(2);
    g->setX(2);
    g->setY(2);
    h->setX(2);
    h->setY(1);
    i->setX(2);
    i->setY(0);

  //             (N, E, S, W)
    a->setExits(b, d, g, NULL);
   b->setExits(b->GetNorthEntrance(), NULL, a,NULL);
    c->setExits(c->GetNorthEntrance(), NULL, d, NULL);
   d->setExits(c, f, h, a);
    e->setExits(e->GetNorthEntrance(), NULL, f, NULL);
   f->setExits(e, NULL, i, d);
   g->setExits(a, NULL, g->GetSouthEntrance(), NULL);
    h->setExits(d, NULL, h->GetSouthEntrance(), NULL);
    i->setExits(f, NULL, i->GetSouthEntrance(), NULL);
        currentSpace =a;
        Room *t=b->GetNorthEntrance();
        cout<<t->longDescription()<<"fff"<<endl;
    WorldMap.resize(3);
    for (int i=0; i<3; i++)
    {
           WorldMap[i].resize(3, NULL);
    }
    WorldMap[1][0] = a;
    WorldMap[0][0] = b;
    WorldMap[0][1] = c;
    WorldMap[1][1] = d;
    WorldMap[0][2] = e;
    WorldMap[1][2] = f;
    WorldMap[2][0] = g;
    WorldMap[2][1] = h;
    WorldMap[2][2] = i;
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
    if(nextRoom!=NULL)
      currentSpace = nextRoom;
      return currentSpace->longDescription();
}
string ZorkUL::goRoom(Space *next){
    if(next!=NULL)
      currentSpace = next;
      return currentSpace->longDescription();
}
