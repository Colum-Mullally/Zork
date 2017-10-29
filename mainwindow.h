#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "ZorkUL.h"


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

private:
    Ui::MainWindow *ui;
    ZorkUL temp;
    QGraphicsScene *scene;
    QPixmap image;


};

#endif // MAINWINDOW_H
