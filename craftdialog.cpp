#include "craftdialog.h"
#include "ui_craftdialog.h"

CraftDialog::CraftDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CraftDialog)
{
    ui->setupUi(this);
    Item p[] = { Item("Burning rag")};
    string l[] = {"Cloth"};
    inventory.push_back(Item("Lighter", l, p, 1, true, true, true));
    l[0] = "Lighter";
    inventory.push_back(Item("Cloth", l, p, 1, true, true, true));
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
    Item i = inventory[index1].craft(inventory[index2].getShortDescription());
    ui->dropMenu1->addItem(QString::fromStdString(i.getShortDescription()));
    ui->dropMenu2->addItem(QString::fromStdString(i.getShortDescription()));
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
    inventory.push_back(i);
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
        if(inventory[index].getRecipes(inventory[indexO].getShortDescription())){
            this->ui->craftedItem->setText(QString::fromStdString(inventory[index].getCraftName()));
            ui->craftButton->setHidden(false);
        }
        else{
            ui->craftButton->setHidden(true);
            this->ui->craftedItem->setText("");
        }
    }
    else
        ui->craftButton->setHidden(true);
}

void CraftDialog::on_dropMenu2_currentIndexChanged(int index)
{
    this->ui->craftedItem->setText("");
    int indexO =  ui->dropMenu1->currentIndex();
    if(indexO > -1){
        if(inventory[index].getRecipes(inventory[indexO].getShortDescription())){
            this->ui->craftedItem->setText(QString::fromStdString(inventory[index].getCraftName()));
            ui->craftButton->setHidden(false);
        }
        else{
            ui->craftButton->setHidden(true);
            this->ui->craftedItem->setText("");
        }
    }
    else
        ui->craftButton->setHidden(true);
}

void CraftDialog::inventoryFill(){
    for(unsigned int i = 0; i < inventory.size(); i++){
      ui->dropMenu1->addItem(QString::fromStdString(inventory[i].getShortDescription()));
      ui->dropMenu2->addItem(QString::fromStdString(inventory[i].getShortDescription()));

    }
}
