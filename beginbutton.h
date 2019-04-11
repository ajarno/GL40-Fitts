#ifndef BEGINBUTTON_H
#define BEGINBUTTON_H

#include <QWidget>
#include "diskbutton.h"

class BeginButton : public DiskButton
{
public:
    BeginButton(QWidget* parent = nullptr);
    ~BeginButton();

private:
    int height_parent, width_parent;
    void centerMe();
};

#endif // BEGINBUTTON_H
