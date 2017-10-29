#include "craftdialog.h"
#include "ui_craftdialog.h"

CraftDialog::CraftDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CraftDialog)
{
    ui->setupUi(this);
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

}

void CraftDialog::on_dropMenu2_currentIndexChanged(int index)
{

}
