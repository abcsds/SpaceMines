#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "sprite.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    spriteN = 3;
    ui->setupUi(this);
    frame = 0;
    Color = 45;
    posX = 0;
    posY = 0;
    pikes.load(":/Pikes");
    cLevel = 5;
    level = 0;
    points = 0;
    Sl = 120;
    Vl = 50;
    Sh = 255;
    Vh = 255;
    capture = cvCaptureFromCAM(0);
    music = 0;

    mensaje = new QMessageBox;
    srand(time(NULL));

    sprites = new sprite(QPoint(rand()%400, 0), QPoint((rand()%(2*cLevel)-cLevel), (rand()%(2*cLevel)-cLevel)));
}

GameWindow::~GameWindow()
{
    cvReleaseCapture(&capture);
    delete mensaje;
    delete ui;
}

void GameWindow::paintEvent(QPaintEvent *e) {


    QPainter painter(this);

    frame = cvQueryFrame(capture);
    IplImage* imgGreenThresh = GetThresholdedImage(frame);
    CvMoments *moments = (CvMoments*)malloc(sizeof(CvMoments));
    cvMoments(imgGreenThresh, moments, 1);

    // The actual moment values
    double moment10 = cvGetSpatialMoment(moments, 1, 0);
    double moment01 = cvGetSpatialMoment(moments, 0, 1);
    double area = cvGetCentralMoment(moments, 0, 0);

    posX = moment10/area;
    posY = moment01/area;
    playerPos = QPoint(posX, posY);
    cv::Mat mt = frame;
    BG = cv2QImage(mt);
    painter.drawImage(0,0,BG);
    QImage pI = pikes.scaled(sqrt(area),sqrt(area));
    painter.drawImage((playerPos.x()-pI.width()/2), (playerPos.y()-pI.height()/2), pI );

    int spriteWidth = sprites->getImg().width();
    int spriteHeight = sprites->getImg().height();

    // Draw sprite
    painter.drawImage((sprites->getPos().x()-(spriteWidth/2)), (sprites->getPos().y()-(spriteHeight/2)), sprites->getImg());
    sprites->move(BG.size());
    if(!(sprites->colides(playerPos, pI.width()/2))) {
        QImage fire(":fire.gif");
        points += 10;
        painter.drawImage((sprites->getPos().x()-(fire.width()/2)), (sprites->getPos().y()-(fire.height()/2)), fire);
        cLevel += 1;
        strP = QString::number(points);

        sprites->setPos(QPoint(rand()%BG.width(), rand()%BG.height()));
        sprites->setRandVel();
    }

    painter.drawText(QPoint(10,10),strP);
    this->update();
    e->accept();
}

QImage GameWindow::cv2QImage(const cv::Mat3b &src) {
    QImage dest(src.cols, src.rows, QImage::Format_ARGB32);
    for (int y = 0; y < src.rows; ++y) {
        const cv::Vec3b *srcrow = src[y];
        QRgb *destrow = (QRgb*)dest.scanLine(y);
        for (int x = 0; x < src.cols; ++x) {
            destrow[x] = qRgba(srcrow[x][2], srcrow[x][1], srcrow[x][0], 255);
        }
    }
    return dest;
}

IplImage* GameWindow::GetThresholdedImage(IplImage *img) {
    IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
    cvCvtColor(img, imgHSV, CV_BGR2HSV);

    IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);
    cvInRangeS(imgHSV, cvScalar((Color-5), Sl, Vl), cvScalar((Color+5), Sh, Vh), imgThreshed);

    cvReleaseImage(&imgHSV);
    return imgThreshed;
}

void GameWindow::setMediaObject(Phonon::MediaObject *m) {
    music = m;

    connect(this->music,SIGNAL(finished()),this,SLOT(msjWindow()));
}

void GameWindow::msjWindow() {
    QString win = "Felicidades! has conseguido " + QString::number(points) + " puntos en 3 minutos!";
    mensaje->setText(win);
    mensaje->show();
    qDebug("Ganaste");
    this->close();
}
