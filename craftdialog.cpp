#include "craftdialog.h"
#include "ui_craftdialog.h"

CraftDialog::CraftDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CraftDialog)
{
    ui->setupUi(this);
    inventory.push_back(Item("Lighter", true, 4));
    inventory.push_back(Item("Vodka", true, 2));
    inventory.push_back(Item("Cloth", true, 1));
    inventoryFill();
    ui->craftedItem->setText("");
    ui->craftButton->setHidden(true);
}

CraftDialog::~CraftDialog()
{
    delete ui;
}

void CraftDialog::on_craftButton_clicked()
{
    int index1 =  ui->dropMenu1->currentIndex();
    int index2 =  ui->dropMenu2->currentIndex();
    string name = craft(index1, index2);
    inventory.push_back(Item(name, true, craftType(index1, index2)));
    ui->dropMenu1->addItem(QString::fromStdString(inventory[inventory.size()-1].getShortDescription()));
    ui->dropMenu2->addItem(QString::fromStdString(inventory[inventory.size()-1].getShortDescription()));
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
    if(inventory.size() >= index1)
        inventory.erase(inventory.begin()+index1, inventory.begin()+index1+1);
    if(inventory.size() >= index2)
        inventory.erase(inventory.begin()+index2, inventory.begin()+index2+1);
}

void CraftDialog::on_cancelButton_clicked()
{
    this->destroy();
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

void CraftDialog::inventoryFill(vector<Item> &inventory, vector<Item> &roomItems){
    for(unsigned int i = 0; i < inventory.size(); i++){
      ui->dropMenu1->addItem(QString::fromStdString(inventory[i].getShortDescription()));
      ui->dropMenu2->addItem(QString::fromStdString(inventory[i].getShortDescription()));

    }
}

string CraftDialog::craft(int index,int index0){
    int first = inventory[index].getMod();
    int that = inventory[index0].getMod();
    if(inventory[index].getHold() || inventory[index0].getHold()){
        ui->craftButton->setHidden(false);
        if(first == 1 && that == 2){
            return inventory[index0].getShortDescription() +" soaked "+inventory[index].getShortDescription();
        }
        else if(first == 2 && that == 1){
            return inventory[index].getShortDescription() +" soaked "+inventory[index0].getShortDescription();
        }
        else if(first == 3 && that >= 4){
            return "Burning Rag";
        }
        else if(first >= 4 && that == 3){
            return "Burning Rag";
        }
        else{
            ui->craftButton->setHidden(true);
            return "";
        }
    }
}

int CraftDialog::craftType(int index,int index0){
    int first = inventory[index].getMod();
    int that =inventory[index0].getMod();
    if(inventory[index].getHold() && inventory[index0].getHold()){
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
