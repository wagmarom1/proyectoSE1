#-------------------------------------------------
#
# Project created by QtCreator 2013-10-08T17:22:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtAppToRunOnRemotePc
TEMPLATE = app

CONFIG += link_pkgconfig
PKGCONFIG += gstreamer-0.10

DEFINES += PROJECT_PATH=\"\\\"$$PWD\\\"\"

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
