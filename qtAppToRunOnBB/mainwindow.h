#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

public slots:
    void OnSelectSong();
    void OnBtnLastPressed();
    void OnBtnPlayStopPressed();
    void OnBtnNextPressed();

};

#endif // MAINWINDOW_H
