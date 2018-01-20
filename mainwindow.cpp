#include "mainwindow.h"
#include <string>
#include <QWidget>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include "game.h"
#include "ui_mainwindow.h"


planet gamePlanet;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);








}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_New_clicked()
{
    // get new planet

    // create planet object and get name, message
    std::string tmp;
    gen_name((rand() % 1000), &tmp);
    std::string msg = "Discovering planet... please stand by.";
    ui->statusBox->document()->setPlainText(QString::fromStdString(msg));
    msg += "\nDiscovered planet: ";
    tmp.insert(0, msg);
    delay(0);
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

    delay(0);
    ui->statusBox->document()->setPlainText(QString::fromStdString(tmp));

    // get graphics

    tmp += "\nScanning geography, please stand by.";

    scene->clear();
    scene->update();

    delay(0);
    ui->statusBox->document()->setPlainText(QString::fromStdString(tmp));

    tmp += "\nGeography scanned.";
    delay(0);
    ui->statusBox->document()->setPlainText(QString::fromStdString(tmp));

    int viewportWidth = ui->graphicsView->width();
    int viewportHeight = ui->graphicsView->height();

    int planetWidth = gamePlanet.size_x;
    int planetHeight = gamePlanet.size_y;

    QBrush redBrush (Qt::red);
    QBrush blueBrush (Qt::blue);
    QBrush colorBrush;
    QPen blackPen (Qt::black);
    QPen noPen (Qt::NoPen);
    blackPen.setWidth(0);

    double cellWidth = double(viewportWidth)/planetWidth;
    double cellHeight = double(viewportHeight)/planetHeight;

       // draw planet
        for (int i = 0; i < planetWidth; i++){
            for(int j = 0; j < planetHeight; j++){
                int value = gamePlanet.map[i][j] * 255;
                QColor current = QColor(value,value/3,255 - value);
                blueBrush.setColor(current);
                scene->addRect(i*cellWidth,j*cellHeight,cellWidth,cellHeight,noPen, blueBrush);
            }
        }

}

void MainWindow::on_statusBox_destroyed()
{

}

void MainWindow::on_Forward_clicked() {
}

void MainWindow::on_Backward_clicked() {
    //rect->moveBy(0,1);
}

void MainWindow::on_Left_clicked() {
    //rect->moveBy(-1,0);
}

void MainWindow::on_Right_clicked() {
    //rect->moveBy(1,0);
}


