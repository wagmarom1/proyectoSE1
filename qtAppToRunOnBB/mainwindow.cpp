#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>  //
#include <QDir>         //
#include <iostream>
#include <QMessageBox> //
#include "mp3admin.h"

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

    // Hacer Split al path para quitarle el nombre del archivo seleccionado y
    // dejar nadamas el path de la ubicacion del archivo, esto para poder listar
    // todos los archivos dentro de la carpeta y asi poder hacer next y prev
    QStringList pathSplited = path.split("/");
    QDir dir(path.remove(pathSplited.at(pathSplited.count()-1)));
    QStringList filter;
    filter << "*.mp3" ;
    dir.setNameFilters(filter);       //Se filtran los archivos mp3
    QFileInfoList list = dir.entryInfoList();   //
    _mp3Admin->setPathList(list);
}

void MainWindow::OnBtnPlayStopPressed()
{
    QString songPath = ui->TextPath->toPlainText(),
            ip = ui->TextIp->toPlainText();

    //Conver Qstring of portNumber to char* for atoi function
    QByteArray ba = ui->TextPort->toPlainText().toLatin1();
    const char *portNumberInChar = ba.data();

    int portNumber = (strcmp(portNumberInChar,"") == 0)? atoi(portNumberInChar) : 0;

    if( songPath != "" &&  ip!= "" && portNumber != 0 && ui->cBRemotaMnt->isChecked() )
    {
        _mp3Admin->playStopSong(true, songPath, ip, portNumber);  //UDP remote playing
    }
    else if(songPath != "")
    {
        _mp3Admin->playStopSong(false, songPath, "", 0);  // Normal Local playing
    }
}

void MainWindow::OnBtnPreviewPressed()
{
    ChangeSongPath(false);
}

void MainWindow::OnBtnNextPressed()
{
    ChangeSongPath(true);
}

void MainWindow::ChangeSongPath(bool isNext)
{
    QString songPath = ui->TextPath->toPlainText();

    QString newSongPath = (isNext)? _mp3Admin->getNextPath(songPath) : _mp3Admin->getPreviewPath(songPath);

    if(newSongPath != "END"){
        ui->TextPath->setText(newSongPath);
    }
    else
    {
        QMessageBox Msgbox;
        Msgbox.setText("No mas archivos");
        Msgbox.exec();
    }
}

