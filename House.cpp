#include "House.h"
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

House::House(string description,int rId):Space(description){
   RandomRoomGenerator(rId);

}


void House::RandomRoomGenerator(int rId){
    vector <Room*> roomList;
    srand(time(NULL)*rId);
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
        RoomMap[k]=new Room*[5];
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
                        break;
                    case 4 :
                        if(RoomMap[x-1][y]!=NULL||RoomMap[x][y+1]!=NULL||RoomMap[x][y-1]!=NULL)
                            RoomMap[x][y]=roomList[nRooms];
                        else
                            nRooms++;

                        break;
                    }
                    switch(y) {
                    case 0 :
                        if(RoomMap[x+1][y]!=NULL||RoomMap[x][y+1]!=NULL||RoomMap[x-1][y]!=NULL)
                            RoomMap[x][y]=roomList[nRooms];
                        else
                            nRooms++;

                        break;
                    case 4 :
                        if(RoomMap[x-1][y]!=NULL||RoomMap[x+1][y]!=NULL||RoomMap[x][y-1]!=NULL)
                            RoomMap[x][y]=roomList[nRooms];
                        else
                            nRooms++;

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

                        break;
                    case 4 :
                        if(RoomMap[x-1][y]!=NULL||RoomMap[x][y-1]!=NULL)
                            RoomMap[x][y]=roomList[nRooms];
                        else
                            nRooms++;

                        break;
                    }
                }

            }

            else if(RoomMap[x+1][y]!=NULL||RoomMap[x-1][y]!=NULL||RoomMap[x][y+1]!=NULL||RoomMap[x][y-1]!=NULL)
            {
                RoomMap[x][y]=roomList[nRooms];

            }
            else if(count==0)
            {
                RoomMap[x][y]=roomList[nRooms];

                count++;
            }
            else
                nRooms++;
        }
        else{
            nRooms++;
        }
    }

    for (int x=0;x<5;x++){
         for(int y=0; y<5;y++){
             if(RoomMap[x][y]!=NULL){
             if(x==4||y==4||x==0||y==0){
             if(x!=y){
                 switch(x) {
                 case 4 :
                        RoomMap[x][y]->setExits(RoomMap[x-1][y],RoomMap[x][y+1],NULL,RoomMap[x][y-1]);
                     break;
                 case 0 :
                        RoomMap[x][y]->setExits(NULL,RoomMap[x][y+1],RoomMap[x+1][y],RoomMap[x][y-1]);
                     break;
                 }
                 switch(y) {
                 case 0 :
                            RoomMap[x][y]->setExits(RoomMap[x-1][y],RoomMap[x][y+1],RoomMap[x+1][y],NULL);
                     break;
                 case 4 :

                        RoomMap[x][y]->setExits(RoomMap[x-1][y],NULL,RoomMap[x+1][y],RoomMap[x][y-1]);
                     break;
                 }
             }
             else{
                 switch(y) {
                 case 4 :
                        RoomMap[x][y]->setExits(RoomMap[x-1][y],NULL,NULL,RoomMap[x][y-1]);

                     break;
                 case 0 :

                        RoomMap[x][y]->setExits(NULL,RoomMap[x][y+1],RoomMap[x+1][y],NULL);
                     break;
                 }
             }
             }
         else
         RoomMap[x][y]->setExits(RoomMap[x-1][y],RoomMap[x][y+1],RoomMap[x+1][y],RoomMap[x][y-1]);
         }
        }
    }
}
Room* House::GetNorthEntrance(){
    Room *temp;
    int marker=-1;
    for(int x=0;x<5;x++){
        for(int y=0;y<5;y++)
        {
            if(y>marker&&RoomMap[x][y]!=NULL){
                temp=RoomMap[x][y];
                x1 = x;
                y1 = y;
            }
        }
    }
     return temp;
}
Room* House::GetSouthEntrance(){
    Room *temp;
    int marker=-1;
    for(int x=0;x<5;x++){
        for(int y=0;y<5;y++)
        {
            if(y<marker&&RoomMap[x][y]!=NULL){
                temp=RoomMap[x][y];
                x1 = x;
                y1 = y;
            }
        }
    }
     return temp;
}

int House::getX(){
    return x1;
}
int House::getY(){
    return y1;
}

void House::write(){
    for(int x=0;x<5;x++){
        for(int y=0;y<5;y++)
        {
            if(RoomMap[x][y]!=NULL){
                cout << RoomMap[x][y]->shortDescription() << "   ";
            }
            else
                cout << "[]  ";
        }

        cout<<endl;
    }

}





