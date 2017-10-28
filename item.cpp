#include "item.h"
Item::Item (string inDescription, int inWeightGrams, float inValue/**, int weaponCheck*/) {
	description = inDescription;
	setWeight(inWeightGrams);
	value = inValue;

	/**weaponCheck(isWeapon);*/
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

bool Item::getRecipes(Item &otherItem){
    string name = otherItem.getShortDescription();
    for(int i = 0; i < (sizeof(recipes)/sizeof(recipes[0])); i++){
        if(name == recipes[i]){
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
        return "sucks 2 b u"; //crafts[craftNum]->getShortDescription()
}

Item Item::craft(){
    Item j("thos");
    return j;//crafts[craftNum];
}
