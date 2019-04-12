#ifndef TARGET_H
#define TARGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPushButton>
#include <QTime>
#include <QVector>
#include <result.h>
#include "randombutton.h"
#include "beginbutton.h"
#include "math.h"

namespace Ui {
class Target;
}

class Target : public QWidget
{
    Q_OBJECT

public:
    explicit Target(QWidget *parent = nullptr, int _nb_cibles = 10, int _t_min = 10, int _t_max = 150, float _a = 0.2f, float _b = 0.1f);
    ~Target();

private:
    double computeDistance();
    void initAll();
    void saveData();

private slots:
    void on_pushButton_retour_clicked();
    void on_pushButton_resultats_clicked();
    void updateTest();
    void beginTest();

private:
    Ui::Target *ui;
    BeginButton *beginButton;
    RandomButton *randomButton;
    QVector<double> *sizes;
    QVector<double> *distances;
    QVector<double> *times;
    QTime *time;
    Result *result;
    int nb_cibles;
    int t_min;
    int t_max;
    float a;
    float b;
};

#endif // TARGET_H
