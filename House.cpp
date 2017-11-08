#include "House.h"
#include "item.h"
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

House::House(string description,int rId, int type):Space(description, type){


    int k, j;
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
   if(type > 0)
        RandomRoomGenerator(rId);

}
House::House(string description,int rId, int type, Space *s):Space(description, type){


    int k, j;
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
   if(type > 0)
        RandomRoomGenerator(rId);
   this->s = s;

}


void House::RandomRoomGenerator(int rId){
    vector <Room*> roomList;
    vector <Item*> itemList;
    srand(time(NULL)*rId);
    int y,x,k,j,i;
    itemList.push_back(new Item("Paper",true,1));
    itemList.push_back(new Item("Rope",true,1));
    itemList.push_back(new Item("Rag",true,1));
    itemList.push_back(new Item("Sock",true,1));
    itemList.push_back(new Item("Oil",true,2));
    itemList.push_back(new Item("Fuel",true,2));
    itemList.push_back(new Item("Vodka",true,2));
    itemList.push_back(new Item("Flint & Steel",true,4));
    itemList.push_back(new Item("Lighter",true,4));

    roomList.push_back( new Room("ra",8));
    roomList.push_back( new Room("rb",8));
    roomList.push_back( new Room("rc",8));
    roomList.push_back( new Room("rd",8));
    roomList.push_back( new Room("re",8));
    roomList.push_back( new Room("rf",8));
    roomList.push_back( new Room("rg",8));
    roomList.push_back( new Room("rh",8));
    roomList.push_back( new Room("ri",8));
    roomList.push_back( new Room("rj",8));
    roomList.push_back( new Room("rk",8));
        roomList[rand()%2+1]->addItem(itemList[rand()%3]);
        roomList[rand()%2+1]->addItem(itemList[rand()%3+4]);
        roomList[rand()%3+6]->addItem(itemList[rand()%3+6]);

    int nRooms= (rand()%7)+3;
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
    bool check = false;
    int marker=-1;
    for(int x=4;x>-1 && !check;x--){
        for(int y=4;y>-1 && !check;y--)
        {
            if(RoomMap[x][y]!=NULL && ! check){
                temp=RoomMap[x][y];
                marker=x;
                check = true;
                x1 = x;
                y1 = y;
                temp->setExits(s,"south");
            }
        }
    }
    return temp;
}
Room* House::GetSouthEntrance(){
    Room *temp;
    bool check = false;
    for(int x=0;x<5 && !false;x++){
        for(int y=0;y<5;y++)
        {
            if(!check&&RoomMap[x][y]!=NULL){
                temp=RoomMap[x][y];
                check=true;
                x1 = x;
                y1 = y;
                temp->setExits(s, "north");
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

string House::writes(){
    string q;
    for(int x=0;x<5;x++){
        for(int y=0;y<5;y++)
        {
            if(RoomMap[x][y]!=NULL){
                q +=  RoomMap[x][y]->shortDescription() + "  ";
            }
            else
                q += "[]  ";
        }

        q+="\n";
    }
    return q;

}

void House::spreadFire(){
    int i , j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(RoomMap[i][j] != NULL){
                if(!RoomMap[i][j]->getFire()){
                    if(RoomMap[i][j]->CheckExit("north")){
                        if(RoomMap[i][j]->exits.at("north")->getFire()){
                            RoomMap[i][j]->setNextFire();
                        }
                    }
                    if(RoomMap[i][j]->CheckExit("south")){
                        if(RoomMap[i][j]->exits.at("south")->getFire()){
                            RoomMap[i][j]->setNextFire();
                        }
                    }
                    if(RoomMap[i][j]->CheckExit("east")){
                        if(RoomMap[i][j]->exits.at("east")->getFire()){
                            RoomMap[i][j]->setNextFire();
                        }
                    }
                    if(RoomMap[i][j]->CheckExit("west")){
                        if(RoomMap[i][j]->exits.at("west")->getFire()){
                            RoomMap[i][j]->setNextFire();
                        }
                    }
                }
            }
        }
    }
    for(i = 0; i < 5; i++){
        for(j = 0 ; j < 5; j++){
            if(RoomMap[i][j] != NULL){
                if(!RoomMap[i][j]->getFire()){
                    if(RoomMap[i][j]->getNextFire()){
                        RoomMap[i][j]->setFire();
                    }
                }
            }
        }
    }
}





