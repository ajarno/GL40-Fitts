#include "beginbutton.h"

BeginButton::BeginButton(QWidget* parent) :
    DiskButton(parent),
    height_parent(parent->height()),
    width_parent(parent->width())
{
    setText("Commencer le test");
    setStyleSheet("QPushButton {font-weight: bold; color: white}");
    adjustSize();
    shapeMe(width());
    centerMe();
}

BeginButton::~BeginButton()
{

}

void BeginButton::centerMe()
{
    move(width_parent/2 - size/2, height_parent/2 - size/2);
}
