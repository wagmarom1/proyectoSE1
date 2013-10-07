#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
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
      QVector<QString> names;

private slots:
    void OnSelectSong();
    void OnBtnPreviewPressed();
    void OnBtnPlayStopPressed();
    void OnBtnNextPressed();
    void ChangeSongPath(bool isNext);

    void on_pauseButton_clicked();
    void on_BtnAddRemote_clicked();
    void on_listWidget_itemSelectionChanged();

    void on_volumeSlider_sliderPressed();
};

#endif // MAINWINDOW_H
