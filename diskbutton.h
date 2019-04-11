#ifndef DISKBUTTON_H
#define DISKBUTTON_H

#include <QWidget>
#include <QPushButton>

class DiskButton : public QPushButton
{
public:
    DiskButton(QWidget *parent = nullptr, int diameter = 50, QColor color = Qt::blue);
    ~DiskButton();
    void shapeMe(int diameter);
    int getSize();

protected:
    int size;

private:
    void colorMe(QColor color);
};

#endif // DISKBUTTON_H
