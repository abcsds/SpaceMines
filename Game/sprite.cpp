#include "sprite.h"

sprite::sprite()
{
    img.load(":/sprite.png");
    r = img.width()/2;
    setRandVel();
}

sprite::sprite(QPoint p)
{
    img.load(":/sprite.png");
    r = img.width()/2;
    pos = p;
    setRandVel();
}

sprite::sprite(QPoint p, QPoint v)
{
    img.load(":/sprite.png");
    r = img.width()/2;
    pos = p;
    vel = v;
}

sprite::~sprite() {
    img.~QImage();
}

bool sprite::colides(QPoint other, int r) {
    if(r>=0&&this->dist(other)<=(r+this->r)) {
        // play sound
        explotion = Phonon::createPlayer(Phonon::MusicCategory, Phonon::MediaSource(":/sound/exp.mp3"));
        explotion->play();

        // change img
        return false;
    }
    else {
        return true;
    }

}

double sprite::dist(QPoint other) {
    double dist = sqrtf(abs((other.x()-pos.x())*(other.x()-pos.x())+(other.y()-pos.y())*(other.y()-pos.y())));
    return dist;
}

void sprite::setPos(QPoint p) {
    pos = p;
}

void sprite::setVel(QPoint v) {
    vel = v;
}

void sprite::setR(int radius) {
    r = radius;
}

QPoint sprite::getPos() {
    return pos;
}

QPoint sprite::getVel() {
    return vel;
}

int sprite::getR() {
    return r;
}

void sprite::move(QSize w) {
    int mx, my;
    mx = (pos.x()+vel.x());
    my = (pos.y()+vel.y());
    if(mx < 0) { mx += w.width();}
    if(my < 0) { my += w.height();}

    pos.setX(mx%w.width());
    pos.setY(my%w.height());
}

void sprite::setRandVel() {
    vel.setX(rand()%10);
    vel.setY(rand()%10);
}

void sprite::setRandPos() {
    pos.setX(0);
    pos.setY(rand()%640);
}

QImage sprite::getImg() {
    return img;
}
