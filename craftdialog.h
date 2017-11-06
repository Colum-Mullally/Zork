#ifndef CRAFTDIALOG_H
#define CRAFTDIALOG_H

#include <QDialog>
#include<QComboBox>
#include "item.h"

using std::vector;

namespace Ui {
class CraftDialog;
}

class CraftDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CraftDialog(QWidget *parent = 0);
    ~CraftDialog();
    string craft(int index, int index0);
    int craftType(int index, int index0);
    void inventoryFill(vector<Item> &roomItems);
    void addInventory(vector<Item> *inv);
    void inventoryFill();
    bool open = false;
    void closeEvent(QCloseEvent *event);
private slots:
    void on_craftButton_clicked();

    void on_cancelButton_clicked();

    void on_dropMenu1_currentIndexChanged(int index);

    void on_dropMenu2_currentIndexChanged(int index);


private:
    vector<Item> *inventory;
    Ui::CraftDialog *ui;
};

#endif // CRAFTDIALOG_H
