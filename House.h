#ifndef House_H
#define House_H
#include "space.h"
#include <map>
#include <string>
#include <vector>
using namespace std;
using std::vector;

class House :public Space {
protected:
    string exitString() override;
public:
    House(string Des);
    string longDescription() override;
};

#endif // House_H
