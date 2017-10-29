#ifndef House_H
#define House_H
#include "space.h"
#include <map>
#include <string>
#include <vector>
using namespace std;
using std::vector;

class House :public Space {
public:
    House(string x): Space(x){}
};

#endif // House_H
