#ifndef House_H
#define House_H
#include "space.h"
#include <map>
#include <string>
#include <vector>
using namespace std;
using std::vector;

class House :public Space {
    Q_OBJECT
protected:
    string exitString() override;
public:
    House(string description);
    string longDescription() override;
};

#endif // House_H
