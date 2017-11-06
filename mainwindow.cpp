#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

    cWindow.addInventory(&inventory);
    ui->setupUi(this);
    outside = false;

    temp=new ZorkUL();
    inventory.push_back(Item("Lighter", true, 4));
    inventory.push_back(Item("Vodka", true, 2));
    inventory.push_back(Item("Cloth", true, 1));
    current = temp->a;
    map = new MapGen(0, 0, temp->b->RoomMap);
    map->setMinimumSize(250,250);
    h = temp->a;
    ui->mapLayout->addWidget(map,1, 2, 2, 2);


    //image.load(":/resource/4aTDsgTECUBfIjB0_nhZjelXP9wVmKKaOcbozI1wktQ.jpg");
    scene =new QGraphicsScene(this);
    scene->setSceneRect(0,0,571,400);
    Player *player=new Player();
    player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(2,5); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);
    ui-> layoutImage -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui-> layoutImage -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui-> layoutImage ->setFixedSize(571,400);

    //TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
   //temp->setFlag(QGraphicsItem::ItemIsFocusable);
   //temp->setFocus();
     // add the player to the scene

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_NorthBtn_clicked()
{
    move("north");
}

void MainWindow::on_EastBtn_clicked()
{
    move("east");
}

void MainWindow::on_WestBtn_clicked()
{
    move("west");
}

void MainWindow::on_SouthBtn_clicked()
{
    move("south");
}

void MainWindow::on_openCrafting_clicked()
{
    cWindow.inventoryFill();
    cWindow.show();
}

void MainWindow::fillList(vector<Item> roomItems){
    ui->inventoryList->clear();
    ui->roomItemList->clear();
    int i;
    for(i = 0; i < inventory.size() ; i++)
        ui->inventoryList->addItem(QString::fromStdString(inventory[i].getShortDescription()));
    for(i = 0; i < roomItems.size(); i++)
        ui->roomItemList->addItem(QString::fromStdString(roomItems[i].getShortDescription()));
}

void MainWindow::move(string dir){

    /*
    int t = current->getType();
    if(current->CheckExit(dir)){
        if(t == 0){
            if(dir == "north"){
                if(h->shortDescription() == "a"){
                    h = temp->b;
                    current = h->GetNorthEntrance();
                    h->write();
                    currentx = h->GetNorthEntrance()->getX();
                    currenty = h->GetNorthEntrance()->getY();
                    cout<<current->shortDescription()<<endl;
                    map->changeRooms(currentx, currenty, h->RoomMap);
                    cout<<"test"<<endl;
                }
                else if(h->shortDescription() == "d"){
                    h = temp->c;
                    current = h->GetNorthEntrance();
                    currentx = h->GetNorthEntrance()->getX();
                    currenty = h->GetNorthEntrance()->getY();
                    cout<<current->shortDescription()<<endl;
                    map->changeRooms(currentx, currenty, h->RoomMap);
                }
                else if(h->shortDescription() == "f"){
                    h = temp->e;
                    current = h->GetNorthEntrance();
                    currentx = h->GetNorthEntrance()->getX();
                    currenty = h->GetNorthEntrance()->getY();
                    cout<<current->shortDescription()<<endl;
                    map->changeRooms(currentx, currenty, h->RoomMap);
                }
            }
            else if(dir == "south"){
                if(h->shortDescription() == "a"){
                    h = temp->g;
                    current = h->GetNorthEntrance();
                    currentx = h->GetNorthEntrance()->getX();
                    currenty = h->GetNorthEntrance()->getY();
                    cout<<current->shortDescription()<<endl;
                    map->changeRooms(currentx, currenty, h->RoomMap);
                }
                else if(h->shortDescription() == "d"){
                    current = temp->h->GetSouthEntrance();
                    h = temp->h;
                    currentx = h->GetNorthEntrance()->getX();
                    currenty = h->GetNorthEntrance()->getY();
                    cout<<current->shortDescription()<<endl;
                    map->changeRooms(currentx, currenty, h->RoomMap);
                }
                else if(h->shortDescription() == "f"){
                    current = temp->i->GetSouthEntrance();
                    h = temp->i;
                    currentx = h->GetNorthEntrance()->getX();
                    currenty = h->GetNorthEntrance()->getY();
                    cout<<current->shortDescription()<<endl;
                    map->changeRooms(currentx, currenty, h->RoomMap);
                }
            }
            else if(dir == "west"){
                if(h->shortDescription() == "d"){
                    h = temp->f;
                    cout<<current->shortDescription()<<endl;
                    map->outside();
                }
                else if(h->shortDescription() == "f"){
                    h = temp->d;
                    cout<<h->longDescription()<<endl;
                    map->outside();
                }
            }
            else if(dir == "east"){
                if(h->shortDescription() == "a"){
                    h = temp->d;
                    cout<<h->longDescription()<<endl;
                    map->outside();
                }
                else if(h->shortDescription() == "d"){
                    h = temp->f;
                    cout<<h->longDescription()<<endl;
                    map->outside();
                }
            }
        }
        else if(t == 8){
                current = h->RoomMap[currentx][currenty]->exits.at(dir);
                if(dir == "north")
                    currentx--;
                else if(dir == "south")
                    currentx++;
                else if(dir == "west")
                    currenty--;
                else if(dir == "east")
                    currenty++;
                map->changeRooms(currentx, currenty, h->RoomMap);
            }
            else{
               map->outside();
               current = current->exits.at(dir);
            }
        }

    ui->label->setText(QString::fromStdString(h->longDescription()+"\n"+h->writes()));*/
    int t = current->getType();
       if(current->CheckExit(dir)){
           if(t == 0){
               if(dir == "north"){
                   if(current->shortDescription() == "a"){
                       current = temp->b->GetNorthEntrance();
                       h = temp->b;
                       currentx = h->GetNorthEntrance()->getX();
                       currenty = h->GetNorthEntrance()->getY();
                       cout<<current->shortDescription()<<endl;
                       map->changeRooms(currentx, currenty, h->RoomMap);
                       cout<<"test"<<endl;
                   }
                   else if(current->shortDescription() == "d"){
                       current = temp->c->GetNorthEntrance();
                       h = temp->c;
                       currentx = h->GetNorthEntrance()->getX();
                       currenty = h->GetNorthEntrance()->getY();
                       cout<<current->shortDescription()<<endl;
                       map->changeRooms(currentx, currenty, h->RoomMap);
                   }
                   else if(current->shortDescription() == "f"){
                       current = temp->e->GetNorthEntrance();
                       h = temp->e;
                       currentx = h->GetNorthEntrance()->getX();
                       currenty = h->GetNorthEntrance()->getY();
                       cout<<current->shortDescription()<<endl;
                       map->changeRooms(currentx, currenty, h->RoomMap);
                   }
               }
               else if(dir == "south"){
                   if(current->shortDescription() == "a"){
                       current = temp->g->GetSouthEntrance();
                       h = temp->g;
                       currentx = h->GetSouthEntrance()->getX();
                       currenty = h->GetSouthEntrance()->getY();
                       h->write();
                       map->changeRooms(currentx, currenty, h->RoomMap);
                       cout<<h->shortDescription()<<" "<<currentx<<" "<<currenty<<endl;
                   }
                   else if(current->shortDescription() == "d"){
                       current = temp->h->GetSouthEntrance();
                       h = temp->h;
                       currentx = h->GetSouthEntrance()->getX();
                       currenty = h->GetSouthEntrance()->getY();
                       cout<<h->shortDescription()<<endl;
                       h->write();;
                       map->changeRooms(currentx, currenty, h->RoomMap);
                   }
                   else if(current->shortDescription() == "f"){
                       current = temp->i->GetSouthEntrance();
                       h = temp->i;
                       currentx = h->GetSouthEntrance()->getX();
                       currenty = h->GetSouthEntrance()->getY();
                       cout<<h->shortDescription()<<endl;
                       h->write();
                       map->changeRooms(currentx, currenty, h->RoomMap);
                   }
               }
               else if(dir == "west"){
                   if(h->shortDescription() == "d"){
                       current = temp->a;
                       h = temp->a;
                       h->write();
                       map->outside();
                   }
                   else if(h->shortDescription() == "f"){
                       current = temp->d;
                       h = temp->d;
                       h->write();
                       map->outside();
                   }
               }
               else if(dir == "east"){
                   if(h->shortDescription() == "a"){;
                       current = temp->d;
                       h = temp->d;
                       map->outside();
                   }
                   else if(h->shortDescription() == "d"){
                       current = temp->f;
                       h = temp->f;
                       map->outside();
                   }
               }
               temp->go(dir);
           }
           else if(t == 8){
                   current = current->exits.at(dir);
                   if(dir == "north")
                       currentx--;
                   else if(dir == "south")
                       currentx++;
                   else if(dir == "west")
                       currenty--;
                   else if(dir == "east")
                       currenty++;
                   if(currentx > 4 || currentx < 0 ||currenty > 4 || currenty < 0 )
                       map->outside();
                   else
                        map->changeRooms(currentx, currenty, h->RoomMap);
                    current = current->exits.at(dir);
               }
               else{
                  map->outside();
                  current = current->exits.at(dir);
               }
           }
       fillList(current->displayItem());
   ui->label->setText(QString::fromStdString(current->longDescription()+"\n"+h->writes()));
}
