#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gW = new GameWindow;
    calib = new Calibrator;
    calib->setGameWindow(gW);

    mColor = 0;
    mSh = 255;
    mSl = 120;
    mVh = 255;
    mVl = 50;

    connect(ui->calibrateButton,SIGNAL(clicked()),this,SLOT(openCalibration()));
    connect(ui->playButton,SIGNAL(clicked()),this,SLOT(Play()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete calib;
    delete gW;
}

void MainWindow::openCalibration() {
    calib->show();
}

void MainWindow::Play() {
//    if(music){
//        music->stop();
//    }
    music = Phonon::createPlayer(Phonon::MusicCategory, Phonon::MediaSource(":/sound/music.mp3"));
    gW->setMediaObject(music);
    music->play();
    gW->show();
}
