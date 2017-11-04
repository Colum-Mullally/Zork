#include "Room.h"
#include "House.h"
#include <random>
string House::longDescription() {
    return "Room = " + description + ".\n" + exitString();
}
string House::exitString() {
    string returnString = "\nexits =";
    for (map<string, Space*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}
House::House(string Des):Space(Des){
        vector <Room*> roomList;
        Room **RoomMap[3] ;
        int y,x,k,j,i;

      roomList.push_back( new Room("a"));
      roomList.push_back( new Room("b"));
      roomList.push_back( new Room("c"));
      roomList.push_back( new Room("d"));
      roomList.push_back( new Room("e"));
      roomList.push_back( new Room("f"));
      roomList.push_back( new Room("g"));
      roomList.push_back( new Room("h"));
      roomList.push_back( new Room("i"));
      roomList.push_back( new Room("j"));
      roomList.push_back( new Room("k"));
       int nRooms= (rand()%6)+3;
        for(k=0 ; k<3; k++)
       {
           RoomMap[k]=new Room*[3];
       }
      /* for(int i=0 ; i<=nRooms ; nRoom--)
       {
           x=rand()%2;
           y=rand()%2;
           RoomMap[x][y]=holder[i];
       }*/
}




