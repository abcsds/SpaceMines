#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Calib/calibrator.h"

namespace Ui {
class MainWindow;
}

class Calibrator;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class Calibrator;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openCalibration();
    void Play();
    
private:
    Ui::MainWindow *ui;
    Calibrator *calib;
    GameWindow *gW;
    Phonon::MediaObject *music;


    unsigned int mColor;
    int mSh, mSl, mVh, mVl;
};

#endif // MAINWINDOW_H
