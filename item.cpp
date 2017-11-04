#include "item.h"
#include "ZorkUL.h"
Item::Item (string inDescription, bool inholdable, int inmod){
    description = inDescription;
    holdable = inholdable;
    mod = inmod;
}
string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
	return " item(s), " + description + ".\n";
}

int Item::getMod(){
    return mod;
}

bool Item::getHold(){
    return holdable;
}
