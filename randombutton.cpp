#include "randombutton.h"

RandomButton::RandomButton(QWidget *parent, int _t_max, int _t_min) :
    DiskButton(parent, generateRand(_t_min, _t_max), Qt::red),
    t_max(_t_max),
    t_min(_t_min),
    height_parent(parent->height()),
    width_parent(parent->width())
{
    moveMe();
}

RandomButton::~RandomButton()
{

}

int RandomButton::generateRand(int min, int max)
{
    return rand()%(max - min) + min;
}

void RandomButton::moveMe()
{
    move(generateRand(0, width_parent - size), generateRand(0, height_parent - size));
}


void RandomButton::resizeMe()
{
    shapeMe(generateRand(t_min, t_max));
}

void RandomButton::updateMe()
{
    resizeMe();
    moveMe();
}
