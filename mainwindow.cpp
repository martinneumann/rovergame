#include "mainwindow.h"
#include <string>
#include <QtWidgets>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "game.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush (Qt::red);
    QBrush blueBrush (Qt::blue);
    QPen blackPen (Qt::black);
    blackPen.setWidth(6);

    ellipse = scene->addEllipse(5,5,100,100,blackPen, redBrush);
    ellipse->setFlag(QGraphicsItem::ItemIsMovable);
    rect = scene->addRect(10,10, 30, 60, blackPen, blueBrush);
    rect->setFlag(QGraphicsItem::ItemIsMovable);



}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_New_clicked()
{
    // get new planet

    // create planet object and get name, message
    planet gamePlanet;
    std::string tmp;
    gen_name((rand() % 1000), &tmp);
    std::string msg = "Discovering planet... please stand by.";
    ui->statusBox->document()->setPlainText(QString::fromStdString(msg));
    msg += "\nDiscovered planet: ";
    tmp.insert(0, msg);
    delay();
    ui->statusBox->document()->setPlainText(QString::fromStdString(tmp));
    create_map(&gamePlanet, rand(), rand() % 10+1, rand() % 10+1, tmp);
    tmp += "\nThe planet's surface size is ";

    tmp += (intToString(gamePlanet.size_x * gamePlanet.size_y));
    tmp += " km².\n";
    ui->statusBox->document()->setPlainText(QString::fromStdString(tmp));

    tmp += gamePlanet.name;
    tmp += "'s dimensions are (";
    tmp += intToString(gamePlanet.size_x);
    tmp += ",";
    tmp += intToString(gamePlanet.size_y);
    tmp += ").";

    delay();
    ui->statusBox->document()->setPlainText(QString::fromStdString(tmp));

    // get graphics

    tmp += "\nScanning geography, please stand by.";
    delay();
    ui->statusBox->document()->setPlainText(QString::fromStdString(tmp));

    tmp += "\nGeography scanned.";
    delay();
    ui->statusBox->document()->setPlainText(QString::fromStdString(tmp));

}

void MainWindow::on_statusBox_destroyed()
{

}

void MainWindow::on_Forward_clicked() {
    rect->moveBy(0,-1);
}

void MainWindow::on_Backward_clicked() {
    rect->moveBy(0,1);
}

void MainWindow::on_Left_clicked() {
    rect->moveBy(-1,0);
}

void MainWindow::on_Right_clicked() {
    rect->moveBy(1,0);
}


