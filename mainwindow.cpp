#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "craftdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    temp.play();
    image.load(":/resource/4aTDsgTECUBfIjB0_nhZjelXP9wVmKKaOcbozI1wktQ.jpg");
    scene =new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->layoutImage->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_NorthBtn_clicked()
{
    ui->label->setText(QString::fromStdString(temp.go("north")));
}

void MainWindow::on_EastBtn_clicked()
{
    ui->label->setText(QString::fromStdString(temp.go("east")));
}

void MainWindow::on_WestBtn_clicked()
{
    ui->label->setText(QString::fromStdString(temp.go("west")));
}

void MainWindow::on_SouthBtn_clicked()
{
    ui->label->setText(QString::fromStdString(temp.go("south")));
}

void MainWindow::on_pushButton_clicked()
{
    cWindow.show();
}
