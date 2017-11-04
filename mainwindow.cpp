#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "craftdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    temp=new ZorkUL();
    image.load(":/resource/4aTDsgTECUBfIjB0_nhZjelXP9wVmKKaOcbozI1wktQ.jpg");
    scene =new QGraphicsScene(this);
    scene->setSceneRect(0,0,571,400);
    scene->addItem(temp);
    ui->layoutImage->setScene(scene);
    ui-> layoutImage -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui-> layoutImage -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui-> layoutImage ->setFixedSize(571,400);

    //TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
   temp->setFlag(QGraphicsItem::ItemIsFocusable);
   temp->setFocus();
     // add the player to the scene



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_NorthBtn_clicked()
{
    ui->label->setText(QString::fromStdString(temp->go("north")));
}

void MainWindow::on_EastBtn_clicked()
{
    ui->label->setText(QString::fromStdString(temp->go("east")));
}

void MainWindow::on_WestBtn_clicked()
{
    ui->label->setText(QString::fromStdString(temp->go("west")));
}

void MainWindow::on_SouthBtn_clicked()
{
    ui->label->setText(QString::fromStdString(temp->go("south")));

}

void MainWindow::on_pushButton_clicked()
{
    cWindow.show();
}
