#include "item.h"
#include "ZorkUL.h"
Item::Item (string inDescription, string inRecipes[], Item inCrafting[]){
    description = inDescription;
    for(int i = 0; i < 1 ; i++){
        cout << "test1" << endl;
        cout << inRecipes[i] << "testing bitch"<< endl;
        recipes[i] = inRecipes[i];
        craftables.push_back(inCrafting[i]);
        crafting[i] = craftables.size() - 1;
    }
}

Item::Item(string inDescription) {
	description = inDescription;
}

void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
	   weightGrams = inWeightGrams;
}

void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
	   value = inValue;
}

void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
}

string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
	return " item(s), " + description + ".\n";
}

bool Item::getRecipes(string name){
    for(int i = 0; i < (sizeof(recipes)/sizeof(recipes[0])); i++){
        if(!recipes[i].compare(name)){
            cout << "item test" << endl;
            craftNum = i;
            return true;
        }
    }
    craftNum = -1;
    return false;

}

int Item::used(){
    return --numOfUses;
}

string Item::getCraftName(){
    if(craftNum == -1){
        return "";
    }
    else
        return craftables[crafting[craftNum]].getShortDescription(); //crafts[craftNum]->getShortDescription()
}

Item Item::craft(){
    return craftables[crafting[craftNum]];
}
