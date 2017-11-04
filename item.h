#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using std::vector;

class Item {
private:
	string description;
	string longDescription;
	int weightGrams;
	float value;
	bool weaponCheck;
    int numOfUses;
    string recipes[10];
    int crafting[10];
    vector<Item> craftables;
    int craftNum;
    bool holdable;
    bool lighter;
    bool fuel;
    bool hasCraft;

public:
    Item (string inDescription, string inRecipes[], Item inCrafting[], int x, bool inholdable, bool infuel, bool inlight);
    Item (string description);
	string getShortDescription();
    string getLongDescription();
    int getWeight();
	void setWeight(int weightGrams);
	float getValue();
	void setValue(float value);
	int getWeaponCheck();
	void setWeaponCheck(int weaponCheck);
    Item craft(string name);
    bool getRecipes(string name);
    string getCraftName();
    int used();
};

#endif /*ITEM_H_*/
