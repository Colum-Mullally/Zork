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
    current = temp->a->GetNorthEntrance();
    int x = current->getX();
    int y = current->getY();
    temp->g->write();
    cout<<endl;
    temp->i->write();
    cout<<endl;
    temp->e->write();
    cout << x << " " << y << "  " << current->shortDescription()<< endl;
    inventory.push_back(Item("Lighter", true, 4));
    inventory.push_back(Item("Vodka", true, 2));
    inventory.push_back(Item("Cloth", true, 1));
    map = new MapGen(x, y, temp);
    map->setMinimumSize(250,250);
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
    ui->label->setText(QString::fromStdString(temp->go("north")));
}

void MainWindow::on_EastBtn_clicked()
{
    ui->label->setText(QString::fromStdString(temp->go("east")));
}

void MainWindow::on_WestBtn_clicked()
{
    ui->label->setText(QString::fromStdString(temp->go("west")));
}

void MainWindow::on_SouthBtn_clicked()
{
       ui->label->setText(QString::fromStdString(temp->go("south")));
}

void MainWindow::on_openCrafting_clicked()
{
    cWindow.inventoryFill();
    cWindow.show();
}

void MainWindow::fillList(vector<Item> &roomItems){
    ui->inventoryList->clear();
    ui->roomItemList->clear();
    int i;
    for(i = 0; i < inventory.size() ; i++)
        ui->inventoryList->addItem(QString::fromStdString(inventory[i].getShortDescription()));
    for(i = 0; i < roomItems.size(); i++)
        ui->roomItemList->addItem(QString::fromStdString(roomItems[i].getShortDescription()));
}
