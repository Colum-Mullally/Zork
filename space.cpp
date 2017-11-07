#include "Space.h"
#include <iostream>
Space::Space(string description, int type){
    this->description = description;
    this->type = type;
    fire = false;
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
void Space::setExits(Space *Dir,string d) {
    if (exits[d] == NULL)
        exits[d] = Dir;
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
void Space::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}
vector<Item>Space::displayItem() {
    return itemsInRoom;
    }

int Space::numberOfItems() {
    return itemsInRoom.size();
}

int Space::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}

void Space::removeItemFromRoom(int location)
{
    itemsInRoom.erase(itemsInRoom.begin()+location);
}

int Space::getX(){
    return x;
}
int Space::getY(){
    return y;
}

void Space::setX(int x1){
    x = x1;
}
void Space::setY(int y1){
    y = y1;
}
int Space::getType(){
    return type;
}
void Space::setFire(){
    fire = true;
}
bool Space::getFire(){
    return fire;
}
