#include "mainwindow.h"
#include "game.h"
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QTextEdit>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget dw;
    MainWindow w;
    int x=dw.width()*1;
    int y=dw.height()*1;
    //w.setFixedSize(x,y);
    w.show();







    return a.exec();

}
