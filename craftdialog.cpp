#include "craftdialog.h"
#include "ui_craftdialog.h"
#include <QCloseEvent>
Item operator +(Item &a, Item &b){

    int first = a.getMod();
    int that = b.getMod();
    int type;
    string name;
    if(first == 1 && that == 2){
        type = 3;
        if(b.getShortDescription() == "Vodka"){
            name = "Vodka Molotov";
        }
        else
            name = b.getShortDescription() + " soaked "+ a.getShortDescription();
    }
    else if(first == 2 && that == 1){
        type = 3;
        if(a.getShortDescription() == "Vodka"){
            name = "Vodka Molotov";
        }
        else
            name = a.getShortDescription() + " soaked "+ b.getShortDescription();
    }
    else if(first == 3 && that >= 4){
        type = 5;
        if(a.getShortDescription() == "Vodka Molotov"){
            name = "Lit Vodka Molotov";
        }
        else
            name = "Burning Rag";
    }
    else if(first >= 4 && that == 3){
        type = 5;
        if(b.getShortDescription() == "Vodka Molotov"){
            name = "Lit Vodka Molotov";
        }
        else
            name = "Burning Rag";
    }
    return Item(name, true, type);
}

CraftDialog::CraftDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CraftDialog)
{
    ui->setupUi(this);
    ui->craftedItem->setText("");
    ui->craftButton->setHidden(true);
}

CraftDialog::~CraftDialog()
{
    delete ui;
}

void CraftDialog::on_craftButton_clicked()
{
    if(!craftChange){
        int index1 =  ui->dropMenu1->currentIndex();
        int index2 =  ui->dropMenu2->currentIndex();
        Item i = (*inventory)[index1] + (*inventory)[index2];
        if((*inventory).size() >= index1){
            if((*inventory)[index1].getMod() < 4)
                (*inventory).erase((*inventory).begin()+index1, (*inventory).begin()+index1+1);
        }
        if((*inventory).size() >= index2){
            if((*inventory)[index2].getMod() < 4)
                (*inventory).erase((*inventory).begin()+index2, (*inventory).begin()+index2+1);
        }
        (*inventory).push_back(i);
        ui->dropMenu1->addItem(QString::fromStdString((*inventory)[(*inventory).size()-1].getShortDescription()));
        ui->dropMenu2->addItem(QString::fromStdString((*inventory)[(*inventory).size()-1].getShortDescription()));
        if(index1 > index2){
            ui->dropMenu2->removeItem(index1);
            ui->dropMenu2->removeItem(index2);
            ui->dropMenu1->removeItem(index1);
            ui->dropMenu1->removeItem(index2);
        }
        else{
            ui->dropMenu2->removeItem(index2);
            ui->dropMenu2->removeItem(index1);
            ui->dropMenu1->removeItem(index2);
            ui->dropMenu1->removeItem(index1);
        }
        craftChange = true;
}
}

void CraftDialog::on_cancelButton_clicked()
{
    this->close();
}

void CraftDialog::on_dropMenu1_currentIndexChanged(int index)
{
    this->ui->craftedItem->setText("");
    int indexO =  ui->dropMenu2->currentIndex();
    if(indexO > -1){
        ui->craftButton->setHidden(false);
        this->ui->craftedItem->setText(QString::fromStdString(craft(index, indexO)));
    }
    else
        ui->craftButton->setHidden(true);
}

void CraftDialog::on_dropMenu2_currentIndexChanged(int index)
{
    this->ui->craftedItem->setText("");
    int indexO =  ui->dropMenu1->currentIndex();
    if(indexO > -1){
        ui->craftButton->setHidden(false);
        this->ui->craftedItem->setText(QString::fromStdString(craft(index, indexO)));
    }
    else
        ui->craftButton->setHidden(true);
}

void CraftDialog::inventoryFill(){
    ui->dropMenu1->clear();
    ui->dropMenu2->clear();
    for(unsigned int i = 0; i < (*inventory).size(); i++){
      ui->dropMenu1->addItem(QString::fromStdString((*inventory)[i].getShortDescription()));
      ui->dropMenu2->addItem(QString::fromStdString((*inventory)[i].getShortDescription()));
    }
/*
    for(unsigned int i = 0; i < roomItems.size(); i++){
      ui->dropMenu1->addItem(QString::fromStdString(roomItems[i].getShortDescription()));
      ui->dropMenu2->addItem(QString::fromStdString(roomItems[i].getShortDescription()));
    }
    */
}

void CraftDialog::addInventory(vector<Item> *inv)
{
    inventory = inv;
}

string CraftDialog::craft(int index,int index0){
    int first = (*inventory)[index].getMod();
    int that = (*inventory)[index0].getMod();
    if((*inventory)[index].getHold() || (*inventory)[index0].getHold()){
        ui->craftButton->setHidden(false);
        if(first == 1 && that == 2){
            if((*inventory)[index0].getShortDescription() == "Vodka"){
                return "Vodka Molotov";
            }
            else
                return (*inventory)[index0].getShortDescription() +" soaked "+(*inventory)[index].getShortDescription();
        }
        else if(first == 2 && that == 1){
            if((*inventory)[index].getShortDescription() == "Vodka"){
                return "Vodka Molotov";
            }
            else
                return (*inventory)[index].getShortDescription() +" soaked "+(*inventory)[index0].getShortDescription();
        }
        else if(first == 3 && that >= 4){
            if((*inventory)[index].getShortDescription() == "Vodka Molotov"){
                return "Lit Vodka Molotov";
            }
            else
                return "Burning Rag";
        }
        else if(first >= 4 && that == 3){
            if((*inventory)[index0].getShortDescription() == "Vodka Molotov"){
                return "Lit Vodka Molotov";
            }
            else
                return "Burning Rag";
        }
        else{
            ui->craftButton->setHidden(true);
            return "";
        }
    }
}

int CraftDialog::craftType(int index,int index0){
    int first = (*inventory)[index].getMod();
    int that =(*inventory)[index0].getMod();
    if((*inventory)[index].getHold() && (*inventory)[index0].getHold()){
        ui->craftButton->setHidden(false);
        if(first == 1 && that == 2){
            return 3;
        }
        else if(first == 2 && that == 1){
            return 3;
        }
        else if(first == 3 && that >= 4){
            return 5;
        }
        else if(first >= 4 && that == 3){
            return 5;
        }
    }
}

void CraftDialog::closeEvent (QCloseEvent *event)
{
    open = false;
}

void CraftDialog::setFalse()
{
    craftChange = false;
}

bool CraftDialog::getCraftChange()
{
    return craftChange;
}

