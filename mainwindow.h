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
#include <QThread>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void move(string dir);
    void closeEvent(QCloseEvent *event);
    bool getOpen();
    CraftDialog cWindow;
    void craftChange();
    bool getCraft();
    void fillList();
    void run();
    void invRun();
    void finish();
    void gameFail();
private slots:

    void on_NorthBtn_clicked();

    void on_EastBtn_clicked();

    void on_WestBtn_clicked();

    void on_SouthBtn_clicked();

    void on_openCrafting_clicked();

    void on_takeAllButton_clicked();

    void on_take1Button_clicked();

    void on_placeButton_clicked();

private:
    bool outside;
    Ui::MainWindow *ui;
    ZorkUL *temp;
    QGraphicsScene *scene;
    QPixmap image;
    Space *current;
    int currentx;
    int currenty;
    vector<Item> inventory;
    vector<Item> roomItems;
    MapGen *map;
    House *h;
    bool craftBool;
    bool open;
};

#endif // MAINWINDOW_H
