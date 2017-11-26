#-------------------------------------------------
#
# Project created by QtCreator 2017-08-10T18:16:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rover
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    graphics.cpp

HEADERS  += mainwindow.h \
    game.h \
    graphics.h

FORMS    += \
    mainwindow.ui
