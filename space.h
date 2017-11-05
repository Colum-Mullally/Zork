#ifndef Space_H
#define Space_H
#include <map>
#include <string>
#include <vector>

using namespace std;
using std::vector;

class Space{
protected:
    map<string, Space*> exits;
    virtual string exitString();
    string description;



public:
    explicit Space(string description);
    void setExits(Space *north, Space *east, Space *south, Space *west);
    Space* nextSpace(string direction);
    string shortDescription();
    virtual string longDescription();



    bool CheckExit(string x);
};
#endif
