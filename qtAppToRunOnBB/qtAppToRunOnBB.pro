#-------------------------------------------------
#
# Project created by QtCreator 2013-10-07T23:18:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtAppToRunOnBB
TEMPLATE = app

CONFIG += link_pkgconfig
PKGCONFIG += gstreamer-0.10


SOURCES += main.cpp\
        mainwindow.cpp \
    mp3admin.cpp

HEADERS  += mainwindow.h \
    mp3admin.h

FORMS    += mainwindow.ui
