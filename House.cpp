#include "House.h"
string House::longDescription() {
    return "House = " + description + ".\n" + exitString();
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

    roomList.push_back( new Room("ra"));
    roomList.push_back( new Room("rb"));
    roomList.push_back( new Room("rc"));
    roomList.push_back( new Room("rd"));
    roomList.push_back( new Room("re"));
    roomList.push_back( new Room("rf"));
    roomList.push_back( new Room("rg"));
    roomList.push_back( new Room("rh"));
    roomList.push_back( new Room("ri"));
    roomList.push_back( new Room("rj"));
    roomList.push_back( new Room("rk"));

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
                        if(RoomMap[x+1][y]!=NULL||RoomMap[x][y+1]!=NULL||RoomMap[x][y-1]!=NULL){
                            RoomMap[x][y]=roomList[nRooms];
                            RoomMap[x][y]->setX(x);
                            RoomMap[x][y]->setY(y);
                        }
                        else
                            nRooms++;
                        break;
                    case 4 :
                        if(RoomMap[x-1][y]!=NULL||RoomMap[x][y+1]!=NULL||RoomMap[x][y-1]!=NULL){
                            RoomMap[x][y]=roomList[nRooms];
                            RoomMap[x][y]->setX(x);
                            RoomMap[x][y]->setY(y);
                        }
                        else
                            nRooms++;

                        break;
                    }
                    switch(y) {
                    case 0 :
                        if(RoomMap[x+1][y]!=NULL||RoomMap[x][y+1]!=NULL||RoomMap[x-1][y]!=NULL){
                            RoomMap[x][y]=roomList[nRooms];
                            RoomMap[x][y]->setX(x);
                            RoomMap[x][y]->setY(y);
                        }
                        else
                            nRooms++;

                        break;
                    case 4 :
                        if(RoomMap[x-1][y]!=NULL||RoomMap[x+1][y]!=NULL||RoomMap[x][y-1]!=NULL){
                            RoomMap[x][y]=roomList[nRooms];
                            RoomMap[x][y]->setX(x);
                            RoomMap[x][y]->setY(y);
                        }
                        else
                            nRooms++;

                        break;
                    }
                }
                else{
                    switch(y) {
                    case 0 :
                        if(RoomMap[x+1][y]!=NULL||RoomMap[x][y+1]!=NULL){
                            RoomMap[x][y]=roomList[nRooms];
                            RoomMap[x][y]->setX(x);
                            RoomMap[x][y]->setY(y);
                        }
                        else
                            nRooms++;

                        break;
                    case 4 :
                        if(RoomMap[x-1][y]!=NULL||RoomMap[x][y-1]!=NULL){
                            RoomMap[x][y]=roomList[nRooms];
                            RoomMap[x][y]->setX(x);
                            RoomMap[x][y]->setY(y);
                        }
                        else
                            nRooms++;

                        break;
                    }
                }

            }

            else if(RoomMap[x+1][y]!=NULL||RoomMap[x-1][y]!=NULL||RoomMap[x][y+1]!=NULL||RoomMap[x][y-1]!=NULL)
            {
                RoomMap[x][y]=roomList[nRooms];
                RoomMap[x][y]->setX(x);
                RoomMap[x][y]->setY(y);
            }
            else if(count==0)
            {
                RoomMap[x][y]=roomList[nRooms];
                RoomMap[x][y]->setX(x);
                RoomMap[x][y]->setY(y);
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
            if(x>marker&&RoomMap[x][y]!=NULL){
                temp=RoomMap[x][y];
                marker=x;
                x1 = x;
                y1 = y;
                temp->setExits(this,"south");
            }
        }
    }
     return temp;
}
Room* House::GetSouthEntrance(){
    Room *temp;
    bool check;
    for(int x=0;x<5;x++){
        for(int y=0;y<5;y++)
        {
            if(check&&RoomMap[x][y]!=NULL){
                temp=RoomMap[x][y];
                check=false;
                x1 = x;
                y1 = y;
                temp->setExits(this,"north");
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
                cout << RoomMap[x][y]->shortDescription() << "  ";
            }
            else
                cout << "[]  ";
        }

        cout<<endl;
    }

}





