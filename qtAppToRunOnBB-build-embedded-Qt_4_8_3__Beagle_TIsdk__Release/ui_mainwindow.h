/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Oct 5 19:22:19 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *TextPath;
    QPushButton *BtnSelectSong;
    QLabel *LabelTile;
    QPushButton *BtnLast;
    QPushButton *BtnPlayStop;
    QPushButton *BtnNext;
    QCheckBox *cBRemotaMnt;
    QTextEdit *TextIp;
    QTextEdit *TextPort;
    QLabel *LabelTile_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(569, 373);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TextPath = new QTextEdit(centralWidget);
        TextPath->setObjectName(QString::fromUtf8("TextPath"));
        TextPath->setGeometry(QRect(30, 80, 371, 31));
        BtnSelectSong = new QPushButton(centralWidget);
        BtnSelectSong->setObjectName(QString::fromUtf8("BtnSelectSong"));
        BtnSelectSong->setGeometry(QRect(420, 80, 98, 31));
        LabelTile = new QLabel(centralWidget);
        LabelTile->setObjectName(QString::fromUtf8("LabelTile"));
        LabelTile->setGeometry(QRect(210, 30, 131, 17));
        QFont font;
        font.setFamily(QString::fromUtf8("FreeMono"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        LabelTile->setFont(font);
        LabelTile->setStyleSheet(QString::fromUtf8(""));
        BtnLast = new QPushButton(centralWidget);
        BtnLast->setObjectName(QString::fromUtf8("BtnLast"));
        BtnLast->setGeometry(QRect(30, 190, 98, 31));
        BtnPlayStop = new QPushButton(centralWidget);
        BtnPlayStop->setObjectName(QString::fromUtf8("BtnPlayStop"));
        BtnPlayStop->setGeometry(QRect(240, 190, 98, 31));
        BtnNext = new QPushButton(centralWidget);
        BtnNext->setObjectName(QString::fromUtf8("BtnNext"));
        BtnNext->setGeometry(QRect(430, 190, 98, 31));
        cBRemotaMnt = new QCheckBox(centralWidget);
        cBRemotaMnt->setObjectName(QString::fromUtf8("cBRemotaMnt"));
        cBRemotaMnt->setGeometry(QRect(30, 130, 211, 22));
        TextIp = new QTextEdit(centralWidget);
        TextIp->setObjectName(QString::fromUtf8("TextIp"));
        TextIp->setGeometry(QRect(260, 130, 81, 31));
        TextPort = new QTextEdit(centralWidget);
        TextPort->setObjectName(QString::fromUtf8("TextPort"));
        TextPort->setGeometry(QRect(370, 130, 81, 31));
        LabelTile_2 = new QLabel(centralWidget);
        LabelTile_2->setObjectName(QString::fromUtf8("LabelTile_2"));
        LabelTile_2->setGeometry(QRect(350, 130, 21, 31));
        LabelTile_2->setFont(font);
        LabelTile_2->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 569, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(BtnSelectSong, SIGNAL(clicked()), MainWindow, SLOT(OnSelectSong()));
        QObject::connect(BtnPlayStop, SIGNAL(clicked()), MainWindow, SLOT(OnBtnPlayStopPressed()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        BtnSelectSong->setText(QApplication::translate("MainWindow", "Select Song", 0, QApplication::UnicodeUTF8));
        LabelTile->setText(QApplication::translate("MainWindow", "BB MP3 player", 0, QApplication::UnicodeUTF8));
        BtnLast->setText(QApplication::translate("MainWindow", "Last", 0, QApplication::UnicodeUTF8));
        BtnPlayStop->setText(QApplication::translate("MainWindow", "Play/Stop", 0, QApplication::UnicodeUTF8));
        BtnNext->setText(QApplication::translate("MainWindow", "Next", 0, QApplication::UnicodeUTF8));
        cBRemotaMnt->setText(QApplication::translate("MainWindow", "Reproducir remotamente", 0, QApplication::UnicodeUTF8));
        LabelTile_2->setText(QApplication::translate("MainWindow", ":", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
