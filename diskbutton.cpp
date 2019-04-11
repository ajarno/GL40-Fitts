#include "diskbutton.h"

DiskButton::DiskButton(QWidget *parent, int diameter, QColor color) :
    QPushButton (parent)
{
    colorMe(color);
    shapeMe(diameter);
}

DiskButton::~DiskButton()
{

}

void DiskButton::colorMe(QColor color)
{
    QPalette pal = this->palette();
    pal.setColor(QPalette::Button, color);
    setAutoFillBackground(true);
    setPalette(pal);
    setFlat(true);
}

void DiskButton::shapeMe(int diameter)
{
    QRect rect(0, 0 , diameter, diameter);
    setGeometry(rect);
    QRegion region(rect, QRegion::Ellipse);
    setMask(region);
    size = diameter;
}

int DiskButton::getSize()
{
    return size;
}
