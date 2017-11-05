#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "ZorkUL.h"
#include "craftdialog.h"
#include "Player.h"
#include "House.h"
#include "Room.h"
#include "mapgen.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_NorthBtn_clicked();

    void on_EastBtn_clicked();

    void on_WestBtn_clicked();

    void on_SouthBtn_clicked();

    void on_openCrafting_clicked();

private:
    bool outside;
    Ui::MainWindow *ui;
    ZorkUL *temp;
    QGraphicsScene *scene;
    QPixmap image;
    CraftDialog cWindow;
    MapGen *map;
    void fillList(vector<Item> &roomItems);

};

#endif // MAINWINDOW_H
