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
    rect = scene->addRect(10,10, 30, 60, blackPen, blueBrush);
    rect->setFlag(QGraphicsItem::ItemIsMovable);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_New_clicked()
{

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
}

void MainWindow::on_statusBox_destroyed()
{

}


