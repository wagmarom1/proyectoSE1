#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->move(400,100);
    //Set some graphical details
    ui->LabelTile->setText("<font color='green'>BB MP3 player</font>");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnSelectSong()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "/home",
                                                     tr("MP3 (*.mp3)"));
    ui->TextPath->setText(path);

}

void MainWindow::OnBtnLastPressed()
{

}

void MainWindow::OnBtnPlayStopPressed()
{

}

void MainWindow::OnBtnNextPressed()
{

}


