#include "calibrator.h"
#include "ui_calibrator.h"

Calibrator::Calibrator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calibrator)
{
    ui->setupUi(this);
    gW = 0;
    capture = 0;
    frame = 0;
    capturing = false;
    showThreshold = false;
    showOriginal = false;
    Color = 50;
    imgScribble = NULL;
    Sl = 50;
    Vl = 50;
    Sh = 255;
    Vh = 255;
}

Calibrator::~Calibrator()
{
    cvReleaseCapture(&capture);
    cvDestroyWindow("threshold");
    cvDestroyWindow("video");
    delete ui;
}

IplImage* Calibrator::GetThresholdedImage(IplImage *img) {
    IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
    cvCvtColor(img, imgHSV, CV_BGR2HSV);

    IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);
    cvInRangeS(imgHSV, cvScalar((Color-5), Sl, Vl), cvScalar((Color+5), Sh, Vh), imgThreshed);

    cvReleaseImage(&imgHSV);
    return imgThreshed;
}

void Calibrator::setGameWindow(GameWindow *g) {
    gW = g;
}

//void Calibrator::paintEvent(QPaintEvent *e) {

//          QPainter painter(this);

//          if(capturing) {
//                //printf("position (%d,%d)\n", playerPos.x(), playerPos.y());
//          }
//        this->update();
//        e->accept();
//}

void Calibrator::on_camaraButton_clicked()
{

        if(capturing)
        {
        while(true)
            {
                // Will hold a frame captured from the camera
                frame = 0;
                frame = cvQueryFrame(capture);
                // If we couldn't grab a frame... quit
                if(!frame) break;
                // If this is the first frame, we need to initialize it
//                if(imgScribble == NULL)
//                {
//                    imgScribble = cvCreateImage(cvGetSize(frame), 8, 3);
//                }
//                // Holds the yellow thresholded image (yellow = white, rest = black)
                IplImage* imgGreenThresh = GetThresholdedImage(frame);
                // Calculate the moments to estimate the position of the ball
                CvMoments *moments = (CvMoments*)malloc(sizeof(CvMoments));
                cvMoments(imgGreenThresh, moments, 1);

                // The actual moment values
                double moment10 = cvGetSpatialMoment(moments, 1, 0);
                double moment01 = cvGetSpatialMoment(moments, 0, 1);
                double area = cvGetCentralMoment(moments, 0, 0);

                // Holding the last and current ball positions
                static int posX = 0;
                static int posY = 0;

//                int lastX = posX;
//                int lastY = posY;

                posX = moment10/area;
                posY = moment01/area;

                // Print it out for debugging purposes
//                printf("position (%d,%d)\n", posX, posY);
                playerPos = QPoint(posX, posY);
                QString str = "( " + QString::number(posX) + " , " + QString::number(posY) + " ) ";
                ui->positionLabel->setText(str);

                // We want to draw a line only if its a valid position
//                if(lastX>0 && lastY>0 && posX>0 && posY>0)
//                {
//                    // Draw a yellow line from the previous point to the current point
//                    cvLine(imgScribble, cvPoint(posX, posY), cvPoint(lastX, lastY), cvScalar(0,255,255), 5);
//                }

//                // Add the scribbling image and the frame...
//                        cvAdd(frame, imgScribble, frame);
                        cvShowImage("threshold", imgGreenThresh);
                        cvShowImage("video", frame);

                // Wait for a keypress
                        int c = cvWaitKey(10);
                        if(c!=-1)
                        {
                            // If pressed, break out of the loop
                            cvDestroyWindow("threshold");
                            cvDestroyWindow("video");
                            break;
                        }

                        // Release the thresholded image+moments... we need no memory leaks.. please
                                cvReleaseImage(&imgGreenThresh);
                                delete moments;
            }
        // We're done using the camera. Other applications can now use it
            //cvReleaseCapture(&capture);
            //cvReleaseWindow?();
        }
}

void Calibrator::on_capturarButton_clicked()
{
    capturing = !capturing;
    if (capturing) {
        ui->capturarButton->setText("Detener captura");
        capture = cvCaptureFromCAM(0);
    }
    else {
        cvDestroyWindow("video");
        cvDestroyWindow("threshold");
        ui->capturarButton->setText("Capturar");
        cvReleaseCapture(&capture);
    }
}

void Calibrator::on_colorSlider_valueChanged(int value)
{
    //printf("H = %i\n", value);
    Color = value;
    if(gW){gW->Color = value;}
    ui->label->setText(QString::number(value));
}

void Calibrator::on_STopSlider_valueChanged(int value)
{
    if(value>Sl){
        Sh = value;
        if(gW){gW->Sh = value;}
        printf("High Saturation = %i\n", value);
    }
}

void Calibrator::on_SBottomSlider_valueChanged(int value)
{
    if(value<Sh) {
        Sl = value;
        if(gW){gW->Sl = value;}
        printf("Low Saturation = %i\n", value);
    }
}

void Calibrator::on_VTopSilder_valueChanged(int value)
{
    if(value>Vl){
        Vh = value;
        if(gW){gW->Vh = value;}
        printf("High Value = %i\n", value);
    }
}

void Calibrator::on_VBottomSlider_valueChanged(int value)
{
    if(value<Vh) {
        Vl = value;
        if(gW){gW->Vl = value;}
        printf("Low Value = %i\n", value);
    }
}
