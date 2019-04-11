#ifndef TARGET_H
#define TARGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPushButton>
#include <QTime>
#include "randombutton.h"
#include "beginbutton.h"

namespace Ui {
class Target;
}

class Target : public QWidget
{
    Q_OBJECT

public:
    explicit Target(QWidget *parent = nullptr, int _nb_cibles = 10, int _t_min = 10, int _t_max = 150);
    ~Target();

private slots:
    void on_pushButton_retour_clicked();
    void on_pushButton_resultats_clicked();
    void updateTest();
    void beginTest();

private:
    Ui::Target *ui;
    BeginButton *beginButton;
    RandomButton *randomButton;
    int nb_cibles;
    int t_min;
    int t_max;
};

#endif // TARGET_H
