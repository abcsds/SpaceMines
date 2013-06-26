#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>

//#include <cv2qt.h>

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

#include "../Game/gamewindow.h"

namespace Ui {
class Calibrator;
}

class Calibrator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calibrator(QWidget *parent = 0);
    ~Calibrator();
   IplImage* GetThresholdedImage(IplImage* img);
    void setGameWindow(GameWindow *g);

    
private slots:
   void on_camaraButton_clicked();

   void on_capturarButton_clicked();

   void on_colorSlider_valueChanged(int value);

   void on_STopSlider_valueChanged(int value);

   void on_SBottomSlider_valueChanged(int value);

   void on_VTopSilder_valueChanged(int value);

   void on_VBottomSlider_valueChanged(int value);

private:
    Ui::Calibrator *ui;
    bool capturing;
    bool showThreshold;
    bool showOriginal;
    bool showPoint;
    IplImage* imgScribble;
    IplImage* frame;
    IplImage* frameT;
    QPoint playerPos;
    unsigned int Color;

    int Sh, Sl, Vh, Vl;

    GameWindow *gW;


    //virtual void paintEvent(QPaintEvent *e);
    CvCapture *capture;
};

#endif // MAINWINDOW_H
