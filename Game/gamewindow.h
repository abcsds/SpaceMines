#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QMessageBox>
#include <QTimer>
#include <math.h>
#include <cstdlib>

#include <phonon/AudioOutput>
#include <phonon/MediaObject>
#include <phonon/VolumeSlider>

#include "sprite.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core_c.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>

class sprite;

namespace Ui {
class GameWindow;
}

//class Calibrator;

class GameWindow : public QMainWindow
{
    friend class Calibrator;

    Q_OBJECT
    
public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
   IplImage* GetThresholdedImage(IplImage* img);
   QImage cv2QImage(const cv::Mat3b &src);
   void setMediaObject(Phonon::MediaObject *m);


private:
    Ui::GameWindow *ui;
    bool capturing;
    bool showThreshold;
    bool showOriginal;
    bool showPoint;
    int posX, posY;
    IplImage* imgScribble;
    IplImage* frame;
    IplImage* frameT;
    QPoint playerPos;
    QImage BG;
    QImage pikes;
    unsigned int Color;
    int spriteN;
    sprite* sprites;
    int level;
    int cLevel;
    int points;
    QString strP;
    int Sh, Sl, Vh, Vl;
    QMessageBox *mensaje;
    QTimer *timer;
    int init;

    Phonon::MediaObject *music;
    virtual void paintEvent(QPaintEvent *e);
    CvCapture *capture;

private slots:
    void msjWindow();
};

#endif // GAMEWINDOW_H
