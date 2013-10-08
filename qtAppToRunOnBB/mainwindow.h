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



    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        QVector<QString> names;

        void ChangeSongPath(bool isNext);

    private slots:
        void on_BtnSelectSong_clicked();
        void on_BtnPlayStop_clicked();
        void on_BtnPrev_clicked();
        void on_BtnNext_clicked();

        void on_pauseButton_clicked();
        void on_BtnAddRemote_clicked();
        void on_listWidget_itemSelectionChanged();

        void on_volumeSlider_sliderPressed();



};

#endif // MAINWINDOW_H

