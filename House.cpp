#include "Room.h"
#include "House.h"
#include <random>
#include <ctime>
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

House::House(string description):Space(description){
    vector <Room*> roomList;
    srand(time(NULL));
    Room **RoomMap[6] ;
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

    for(k=0 ; k<5; k++)
    {
        RoomMap[k]=new Room*[6];
    }
    for(k=0 ; k<5; k++)
    {
        for(j=0;j<5;j++)
        {
            RoomMap[k][j]=NULL;
        }
    }
    int nRooms= (rand()%7)+3;

    cout<<nRooms<<endl;
    int count=0;
    for(int i=0 ; i<nRooms ; nRooms--)
    {
        x=rand()%4;
        y=rand()%4;

        bool check=false;
        if(RoomMap[x][y]==NULL){
            if(x==4||y==4||x==0||y==0){
                if(x!=y){
                    switch(x) {
                    case 0 :
                        if(RoomMap[x+1][y]!=NULL||RoomMap[x][y+1]!=NULL||RoomMap[x][y-1]!=NULL)
                            RoomMap[x][y]=roomList[nRooms];
                        else
                            nRooms++;
                        cout<<x<< "  "<<y<<"  "<<endl;
                        break;
                    case 4 :
                        if(RoomMap[x-1][y]!=NULL||RoomMap[x][y+1]!=NULL||RoomMap[x][y-1]!=NULL)
                            RoomMap[x][y]=roomList[nRooms];
                        else
                            nRooms++;
                        cout<<x<< "  "<<y<<"  "<<endl;
                        break;
                    }
                    switch(y) {
                    case 0 :
                        if(RoomMap[x+1][y]!=NULL||RoomMap[x][y+1]!=NULL||RoomMap[x-1][y]!=NULL)
                            RoomMap[x][y]=roomList[nRooms];
                        else
                            nRooms++;
                        cout<<x<< "  "<<y<<"  "<<endl;
                        break;
                    case 4 :
                        if(RoomMap[x-1][y]!=NULL||RoomMap[x+1][y]!=NULL||RoomMap[x][y-1]!=NULL)
                            RoomMap[x][y]=roomList[nRooms];
                        else
                            nRooms++;
                        cout<<x<< "  "<<y<<"  "<<endl;
                        break;
                    }
                }
                else{
                    switch(y) {
                    case 0 :
                        if(RoomMap[x+1][y]!=NULL||RoomMap[x][y+1]!=NULL)
                            RoomMap[x][y]=roomList[nRooms];
                        else
                            nRooms++;
                        cout<<x<< "  "<<y<<"  "<<endl;
                        break;
                    case 4 :
                        if(RoomMap[x-1][y]!=NULL||RoomMap[x][y-1]!=NULL)
                            RoomMap[x][y]=roomList[nRooms];
                        else
                            nRooms++;
                        cout<<x<< "  "<<y<<"  "<<endl;
                        break;
                    }
                }

            }

            else if(RoomMap[x+1][y]!=NULL||RoomMap[x-1][y]!=NULL||RoomMap[x][y+1]!=NULL||RoomMap[x][y-1]!=NULL)
            {
                RoomMap[x][y]=roomList[nRooms];
                cout<<x<< "  "<<y<<"  "<<endl;
            }
            else if(count==0)
            {
                RoomMap[x][y]=roomList[nRooms];
                cout<<x<< "  "<<y<<"  "<<endl;
                count++;
            }
            else
                nRooms++;
        }
        else{
            nRooms++;
        }
    }
    for(k=0 ; k<5; k++)
    {
        for(j=0;j<5;j++)
        {
            if(RoomMap[k][j]!=NULL)
                cout<<RoomMap[k][j]->shortDescription()<<"  ";
            else
                cout<<"[]"<<"  ";
        }
        cout<<endl;
    }

}





