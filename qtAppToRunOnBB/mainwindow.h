#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mp3admin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    mp3Admin* _mp3Admin;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

private slots:
    void OnSelectSong();
    void OnBtnPreviewPressed();
    void OnBtnPlayStopPressed();
    void OnBtnNextPressed();
    void ChangeSongPath(bool isNext);

};

#endif // MAINWINDOW_H
