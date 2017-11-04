#ifndef Space_H
#define Space_H
#include <map>
#include <string>
#include <vector>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
using namespace std;
using std::vector;

class Space:public QObject,public QGraphicsRectItem{
     Q_OBJECT
protected:
    map<string, Space*> exits;
    virtual string exitString();
    string description;



public:
    explicit Space(string description,QGraphicsItem * parent=0);
    void setExits(Space *north, Space *east, Space *south, Space *west);
    Space* nextSpace(string direction);
    string shortDescription();
    virtual string longDescription();



};
#endif
