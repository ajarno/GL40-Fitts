#ifndef RANDOMBUTTON_H
#define RANDOMBUTTON_H

#include <QWidget>
#include "diskbutton.h"

class RandomButton : public DiskButton
{
public:
    RandomButton(QWidget *parent, int _t_max, int _t_min);
    ~RandomButton();
    void updateMe();

private:
    int t_max, t_min, height_parent, width_parent;
    int generateRand(int min, int max);
    void moveMe();
    void resizeMe();
};

#endif // RANDOMBUTTON_H
