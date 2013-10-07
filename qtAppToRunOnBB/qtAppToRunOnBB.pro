#-------------------------------------------------
#
# Project created by QtCreator 2013-09-30T21:22:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += link_pkgconfig
PKGCONFIG += gstreamer-0.10

TARGET = qtAppToRunOnBB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mp3admin.cpp

HEADERS  += mainwindow.h \
    mp3admin.h

FORMS    += mainwindow.ui
