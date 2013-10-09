#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QProcess p;
    p.start();
    p.waitForFinished(-1);

    QString p_stdout = p.readAllStandardOutput();
    QString p_stderr = p.readAllStandardError();
}

MainWindow::~MainWindow()
{
    delete ui;
}
