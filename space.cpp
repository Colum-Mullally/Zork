#include "Space.h"
#include <iostream>
Space::Space(string description){
    this->description = description;
}

void Space::setExits(Space *north, Space *east, Space *south, Space *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}
bool Space::CheckExit(string x) {
    if (exits[x] != NULL)
        return true;
    else
        return false;
}
string Space::shortDescription() {
    return description;
}

string Space::longDescription() {
    return "Space = " + description + ".\n" + exitString();
}

string Space::exitString() {
    string returnString = "\nexits =";
    for (map<string, Space*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

Space* Space::nextSpace(string direction) {
    map<string, Space*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no Space in that direction.
    return next->second; // If there is a Space, remove the "second" (Space*)
                // part of the "pair" (<string, Space*>) and return it.
}
