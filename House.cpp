#include "House.h"
#include <random>

//gfghfd
House::House(string description) {
    this->description = description;//testing
}

void House::setExits(House *north, House *east, House *south, House *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}
string House::shortDescription() {
    return description;
}

string House::longDescription() {
    return "House = " + description + ".\n" + exitString();
}

string House::exitString() {
    string returnString = "\nexits =";
    for (map<string, House*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

House* House::nextHouse(string direction) {
    map<string, House*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no House in that direction.
    return next->second; // If there is a House, remove the "second" (House*)
                // part of the "pair" (<string, House*>) and return it.
}
