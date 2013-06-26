#ifndef SPRITE_H
#define SPRITE_H

#include <QDebug>

#include <phonon/AudioOutput>
#include <phonon/MediaObject>
#include <phonon/VolumeSlider>

#include "gamewindow.h"

//#include <cstdlib>

class GameWindow;

class sprite
{
public:
    sprite();
    sprite(QPoint p);
    sprite(QPoint p, QPoint v);
    ~sprite();
    void spriteSet(QPoint p, QPoint v);
    bool colides(QPoint other, int r);
    double dist(QPoint other);
    void setPos(QPoint p);
    void setVel(QPoint v);
    void setR(int radius);
    void setRandVel();
    void setRandPos();
    QPoint getPos();
    QPoint getVel();
    QImage getImg();
    int getR();
    void move(QSize w);

    Phonon::MediaObject *explotion;

private:
    QPoint pos;
    QPoint vel;
    int r;
    QImage img;
};

#endif // SPRITE_H
