#include "craftdialog.h"
#include "ui_craftdialog.h"

CraftDialog::CraftDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CraftDialog)
{
    ui->setupUi(this);
    inventoryFill();
}

CraftDialog::~CraftDialog()
{
    delete ui;
}

void CraftDialog::on_craftButton_clicked()
{

}

void CraftDialog::on_cancelButton_clicked()
{
    this->destroy();
}

void CraftDialog::on_dropMenu1_currentIndexChanged(int index)
{
    this->ui->craftedItem->setText("");
    int indexO =  ui->dropMenu2->currentIndex();
    if(!indexO > -1){
        indexO = 0;
    }
    if(inventory[index].getRecipes(inventory[indexO].getShortDescription())){
        this->ui->craftedItem->setText(QString::fromStdString(inventory[index].getCraftName()));
        cout << inventory[index].getCraftName() << endl;
    }
    else
        this->ui->craftedItem->setText("");
}

void CraftDialog::on_dropMenu2_currentIndexChanged(int index)
{
    this->ui->craftedItem->setText("");
    int indexO =  ui->dropMenu1->currentIndex();
    if(!indexO > -1){
        indexO = 0;
    }
    if(inventory[index].getRecipes(inventory[indexO].getShortDescription()))
        this->ui->craftedItem->setText(QString::fromStdString(inventory[index].getCraftName()));
    else
        this->ui->craftedItem->setText("");
}

void CraftDialog::inventoryFill(){
    Item p[] = { Item("Burning rag")};
    string l[] = {"Cloth"};
    inventory.push_back(Item("Lighter", l, p));
    l[0] = "Lighter";
    inventory.push_back(Item("Cloth", l, p));
    for(unsigned int i = 0; i < inventory.size(); i++){
      ui->dropMenu1->addItem(QString::fromStdString(inventory[i].getShortDescription()));
      ui->dropMenu2->addItem(QString::fromStdString(inventory[i].getShortDescription()));

    }
}
