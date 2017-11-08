#include <iostream>
using namespace std;
#include "ZorkUL.h"
#include "mainwindow.h"
#include <QApplication>
#include "windowthreads.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    windowThreads wt;
    wt.start();
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
}
