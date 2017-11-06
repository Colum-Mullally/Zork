#include "Room.h"
string Room::longDescription() {
    return "Room = " + description + ".\n" + exitString();
}
string Room::exitString() {
    string returnString = "\nexits =";
    for (map<string, Space*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

Room::Room(string x, int type): Space(x, type){
    fire=false;
}

void Room::setX(int x2){
    x1 = x2;
}

void Room::setY(int y2){
    y = y2;
}

int Room::getX(){
    return x1;
}

int Room::getY(){
    return y;
}



