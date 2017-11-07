#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include "QTimer"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

    cWindow.addInventory(&inventory);
    ui->setupUi(this);
    outside = false;
    craftBool = false;
    open = true;
    temp=new ZorkUL();
    inventory.push_back(Item("Lighter", true, 4));
    inventory.push_back(Item("Vodka", true, 2));
    inventory.push_back(Item("Cloth", true, 1));
    current = temp->a;
    map = new MapGen(0, 0, temp->a->RoomMap);
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
    fillList();

    //TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
   //temp->setFlag(QGraphicsItem::ItemIsFocusable);
   //temp->setFocus();
     // add the player to the scene

    if(!current->CheckExit("north"))
        ui->NorthBtn->setHidden(true);
     else
        ui->NorthBtn->setHidden(false);
    if(!current->CheckExit("east"))
        ui->EastBtn->setHidden(true);
    else
        ui->EastBtn->setHidden(false);
    if(!current->CheckExit("south"))
        ui->SouthBtn->setHidden(true);
    else
        ui->SouthBtn->setHidden(false);
    if(!current->CheckExit("west"))
        ui->WestBtn->setHidden(true);
    else
        ui->WestBtn->setHidden(false);

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
    craftBool = true;
}

void MainWindow::fillList(){
    this->roomItems = current->displayItem();
    ui->inventoryList->clear();
    ui->roomItemList->clear();
    int i;
    for(i = 0; i < inventory.size() ; i++)
        ui->inventoryList->addItem(QString::fromStdString(inventory[i].getShortDescription()));
    for(i = 0; i < roomItems.size(); i++)
        ui->roomItemList->addItem(QString::fromStdString(roomItems[i].getShortDescription()));
}

void MainWindow::craftChange()
{
    craftBool = false;
}

bool MainWindow::getCraft()
{
    return craftBool;
}
void MainWindow::on_takeAllButton_clicked()
{
    for(int i = 0; i < roomItems.size(); i++){
        ui->inventoryList->addItem(QString::fromStdString(roomItems[i].getShortDescription()));
        inventory.push_back( roomItems[i]);
        current->removeItemFromRoom(1);
    }
        ui->roomItemList->clear();
        fillList();
    //current->deleteAll();

}


void MainWindow::move(string dir){
    int t = current->getType();
       if(current->CheckExit(dir)){
           if(h->getFire()){
               h->spreadFire();
           }
           if(t == 0){
               if(dir == "north"){
                   if(current->shortDescription() == "a"){
                       current = temp->b->GetNorthEntrance();
                       h = temp->b;
                       currentx = h->GetNorthEntrance()->getX();
                       currenty = h->GetNorthEntrance()->getY();
                       cout<<current->shortDescription()<<endl;
                       map->changeRooms(currentx, currenty, h->RoomMap);
                       map->setHidden(false);
                   }
                   else if(current->shortDescription() == "d"){
                       current = temp->c->GetNorthEntrance();
                       h = temp->c;
                       currentx = h->GetNorthEntrance()->getX();
                       currenty = h->GetNorthEntrance()->getY();
                       cout<<current->shortDescription()<<endl;
                       map->changeRooms(currentx, currenty, h->RoomMap);
                       map->setHidden(false);
                   }
                   else if(current->shortDescription() == "f"){
                       current = temp->e->GetNorthEntrance();
                       h = temp->e;
                       currentx = h->GetNorthEntrance()->getX();
                       currenty = h->GetNorthEntrance()->getY();
                       cout<<current->shortDescription()<<endl;
                       map->changeRooms(currentx, currenty, h->RoomMap);
                       map->setHidden(false);
                   }
               }
               else if(dir == "south"){
                   if(current->shortDescription() == "a"){
                       current = temp->g->GetSouthEntrance();
                       h = temp->g;
                       currentx = h->GetSouthEntrance()->getX();
                       currenty = h->GetSouthEntrance()->getY();
                       map->changeRooms(currentx, currenty, h->RoomMap);
                       map->setHidden(false);
                   }
                   else if(current->shortDescription() == "d"){
                       current = temp->h->GetSouthEntrance();
                       h = temp->h;
                       currentx = h->GetSouthEntrance()->getX();
                       currenty = h->GetSouthEntrance()->getY();
                       map->changeRooms(currentx, currenty, h->RoomMap);
                       map->setHidden(false);
                   }
                   else if(current->shortDescription() == "f"){
                       current = temp->i->GetSouthEntrance();
                       h = temp->i;
                       currentx = h->GetSouthEntrance()->getX();
                       currenty = h->GetSouthEntrance()->getY();
                       cout<<h->shortDescription()<<endl;
                       map->changeRooms(currentx, currenty, h->RoomMap);
                       map->setHidden(false);
                   }
               }
               else if(dir == "west"){
                   if(current->shortDescription() == "d"){
                       current = temp->a;
                       h = temp->a;
                       map->setHidden(true);
                   }
                   else if(current->shortDescription() == "f"){
                       current = temp->d;
                       h = temp->d;
                       map->setHidden(true);
                   }
               }
               else if(dir == "east"){
                   if(current->shortDescription() == "a"){;
                       current = temp->d;
                       h = temp->d;
                       map->setHidden(true);
                   }
                   else if(current->shortDescription() == "d"){
                       current = temp->f;
                       h = temp->f;
                       map->setHidden(true);
                   }
               }
               temp->go(dir);
           }
           else if(t == 8){
                   if(dir == "north")
                       currentx--;
                   else if(dir == "south")
                       currentx++;
                   else if(dir == "west")
                       currenty--;
                   else if(dir == "east")
                       currenty++;
                   if(currentx > 4 || currentx < 0 ||currenty > 4 || currenty < 0 )
                       map->setHidden(true);
                   else{
                        map->changeRooms(currentx, currenty, h->RoomMap);
                        map->setHidden(false);
                   }
                   if(current->exits.at(dir)->getType() != 8){
                       if(current->exits.at(dir)->shortDescription() == "a")
                           h = temp->a;
                       else if(current->exits.at(dir)->shortDescription() == "d")
                           h = temp->d;
                       else if(current->exits.at(dir)->shortDescription() == "f")
                           h = temp->f;
                   }
                   current = current->exits.at(dir);
                   if(current->getType() == 0)
                       map->setHidden(true);
               }
               else{
                  map->setHidden(true);
                  current = current->exits.at(dir);
               }
           }
       fillList();
   ui->label->setText(QString::fromStdString(current->longDescription()+"\n"+h->writes()));
   if(h->getFire()){
       if(current->getType() == 8){
           if(current->getFire()){
               gameFail();
           }
       }
   }
   if(!current->CheckExit("north"))
       ui->NorthBtn->setHidden(true);
    else
       ui->NorthBtn->setHidden(false);
   if(!current->CheckExit("east"))
       ui->EastBtn->setHidden(true);
   else
       ui->EastBtn->setHidden(false);
   if(!current->CheckExit("south"))
       ui->SouthBtn->setHidden(true);
   else
       ui->SouthBtn->setHidden(false);
   if(!current->CheckExit("west"))
       ui->WestBtn->setHidden(true);
   else
       ui->WestBtn->setHidden(false);
}


void MainWindow::on_take1Button_clicked()
{
    if(ui->roomItemList->currentIndex().row()!=-1){
      ui->inventoryList->addItem(QString::fromStdString(roomItems[ui->roomItemList->currentIndex().row()].getShortDescription()));
       inventory.push_back(roomItems[ui->roomItemList->currentIndex().row()]);
       current->removeItemFromRoom(ui->roomItemList->currentIndex().row());
       ui->roomItemList->takeItem(ui->roomItemList->currentIndex().row());
       fillList();
    }
    // inventory.push_back( roomItems[i]);}
     //ui->roomItemList->clear();
}

void MainWindow::on_placeButton_clicked()
{
    if(ui->inventoryList->currentIndex().row()!=-1){
        if(inventory[ui->inventoryList->currentIndex().row()].getMod() == 5){
            if(current->getType() == 8){
               h->setFire();
               current->setNextFire();
            }
        }
        else{

            ui->roomItemList->addItem(QString::fromStdString(inventory[ui->inventoryList->currentIndex().row()].getShortDescription()));
            roomItems.push_back(inventory[ui->inventoryList->currentIndex().row()]);
            current->addItem(&inventory[ui->inventoryList->currentIndex().row()]);
        }
        inventory.erase(inventory. begin() + ui->inventoryList->currentIndex().row());

        delete ui->inventoryList->takeItem(ui->inventoryList->currentIndex().row());
        fillList();
    }
}


void MainWindow::closeEvent (QCloseEvent *event)
{
    if(open){
        open = false;
        event->ignore();
        finish();
    }
}

bool MainWindow::getOpen(){
    return open;
}

void MainWindow::finish(){
    QTimer::singleShot(1000, this, SLOT(close()));
}

void MainWindow::gameFail(){
     cout <<"You Lose!" << endl;
     close();
}

