#-------------------------------------------------
#
# Project created by QtCreator 2022-04-14T10:59:46
#
#-------------------------------------------------

QT       += core gui
CONFIG += qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = signalgeneration
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plot.cpp \
    samplingthread.cpp

HEADERS  += mainwindow.h \
    plot.h \
    samplingthread.h

FORMS    += mainwindow.ui
