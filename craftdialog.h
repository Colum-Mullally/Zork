#ifndef CRAFTDIALOG_H
#define CRAFTDIALOG_H

#include <QDialog>

namespace Ui {
class CraftDialog;
}

class CraftDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CraftDialog(QWidget *parent = 0);
    ~CraftDialog();

private slots:
    void on_craftButton_clicked();

    void on_cancelButton_clicked();

    void on_dropMenu1_currentIndexChanged(int index);

    void on_dropMenu2_currentIndexChanged(int index);

private:
    Ui::CraftDialog *ui;
};

#endif // CRAFTDIALOG_H
