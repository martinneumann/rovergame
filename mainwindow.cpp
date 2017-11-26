#include "mainwindow.h"
#include <string>
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
    //QTextBrowser statusBox = new QTextBrowser();

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
