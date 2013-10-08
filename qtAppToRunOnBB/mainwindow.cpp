#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "mp3admin.h"
#include <QDir>
#include <iostream>
#include <QMessageBox>


mp3Admin* _mp3Admin = new mp3Admin;
QString ImagePath;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->move(0,0);
    //Set some graphical details
    ui->listWidget->addItem("Local");
    ui->volumeSlider->setValue(50);
    names.append("Local");
    system(" amixer sset 'DAC1 Digital Fine' 50");
    system("amixer sset 'Headset' 2 ");
    system("amixer sset 'HeadsetL Mixer AudioL1' on");
    system("amixer sset 'HeadsetL Mixer AudioR1' on");

    QStringList ImagePathSplit; ImagePathSplit << "<img src='" << PROJECT_PATH << "/Images/";
    ImagePath = ImagePathSplit.join("");

    ui->AddRemoteLabel->setText(ImagePath + "add.png'/><br>" );
    ui->StopPlaylabel->setText(ImagePath + "play.png'/><br>");
    ui->PauseLabel->setText(ImagePath + "pause.png'/><br>");
    ui->SelectSongLabel->setText(ImagePath + "search.png'/><br>");
    ui->BackGndLabel->setText(ImagePath + "bg3.jpeg'/><br>");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnSelectSong_clicked()
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
    QFileInfoList list = dir.entryInfoList();   // lista los archivos
    _mp3Admin->setPathList(list);
}

void MainWindow::on_BtnPlayStop_clicked()
{
    // Obtener el indice seleccionado
    QModelIndex m_activedIndex = ui->listWidget->currentIndex();
    int  selectedIndex = m_activedIndex.row();
    g_print("Selected Index: %i \n", selectedIndex);

    if(selectedIndex == -1)
    {
        g_print("YOU HAVE TO SELECT AN INDEX\n");
    }
    else if(selectedIndex == 0) //Local
    {

        if(_mp3Admin->getPlayFlag()){
            // haga el stop
            ui->StopPlaylabel->setText(ImagePath + "play.png'/><br>");
            _mp3Admin->setPlayFlag(false); //El timeout_callback? detiene la cancion
            g_print ("STOP\n");
        }
        else
        {
            //haga play

            QString songPath = ui->TextPath->toPlainText();

            if(songPath != "")
            {
                ui->StopPlaylabel->setText(ImagePath + "stop.png'/><br>");
                _mp3Admin->setPlayFlag(true);
                _mp3Admin->playStopSong(false, songPath, "", 0);  // Normal Local playing
                g_print ("PLAY LOCAL\n");

            }
        }
    }
    else //remoto
    {
         g_print ("Entra a remoto\n");
        _mp3Admin->stopRemoteSong(selectedIndex - 1);
    }
}

void MainWindow::on_BtnPrev_clicked()
{
    ChangeSongPath(false);
}

void MainWindow::on_BtnNext_clicked()
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
        Msgbox.setText("No hay mas archivos...");
        Msgbox.exec();
    }
}


void MainWindow::on_pauseButton_clicked()
{
    QModelIndex m_activedIndex = ui->listWidget->currentIndex();
    int  selectedIndex = m_activedIndex.row();
    g_print("Selected Index: %i \n", selectedIndex);
    if(selectedIndex == -1)
    {
        g_print("YOU HAVE TO SELECT AN INDEX\n");
    }
    else if(selectedIndex == 0)
    {
        _mp3Admin->pauseLocalSong();
    }
    else
    {
         _mp3Admin->pauseRemoteSong(selectedIndex -1);
    }
}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    QModelIndex m_activedIndex = ui->listWidget->currentIndex();
    int  selectedIndex = m_activedIndex.row();
    g_print("Selected Index: %i \n", selectedIndex);
    QString control = names[selectedIndex];
    ui->LabelTile_6->setText(control);
}

void MainWindow::on_BtnAddRemote_clicked()
{
    g_print ("ADD REMOTE\n");
    QString songPath = ui->TextPath->toPlainText(),
            ip = ui->TextIp->toPlainText(),
            nameRemote = ui->TextName->toPlainText();

    //Conver Qstring of portNumber to char* for atoi function
    QByteArray ba = ui->TextPort->toPlainText().toLatin1();
    const char *portNumberInChar = ba.data();

    int portNumber = (portNumberInChar != "")? atoi(portNumberInChar) : 0;

    if( songPath != "" &&  ip!= "" && portNumber != 0  && nameRemote != "")
    {
        names.append(nameRemote);
        ui->listWidget->addItem(nameRemote + " " + ip + ":" + QString::number(portNumber));
        _mp3Admin->playStopSong(true, songPath, ip, portNumber);  //UDP remote playing
    }
}

void MainWindow::on_volumeSlider_sliderPressed()
{
    int value = ui->volumeSlider->value();
    QString cmd = " amixer sset 'DAC1 Digital Fine' " + value;
    QByteArray bb = cmd.toLatin1();
    const char *Alsacmd = bb.data();
    system(Alsacmd);
}

