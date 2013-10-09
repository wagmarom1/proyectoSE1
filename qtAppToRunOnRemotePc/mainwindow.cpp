#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->move(0,0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LIstenButton_clicked()
{
    if(ui->IPText->toPlainText().compare("") != 0)
        system("gst-launch-0.10 udpsrc multicast-group=192.168.0.102 auto-multicast=true port=3000 caps='application/x-rtp, media=(string)audio, clock-rate=(int)8000, encoding-name=(string)PCMU, payload=(int)0, ssrc=(guint)1350777638, clock-base=(guint)2942119800, seqnum-base=(guint)47141' ! rtppcmudepay ! mulawdec ! pulsesink");

}
