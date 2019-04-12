#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <algorithm>
#include <qcustomplot.h>

namespace Ui {
class Result;
}

class Result : public QWidget
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr, QVector<double> *_sizes = nullptr,
                    QVector<double> *_distances = nullptr,
                    QVector<double> *_times = nullptr,
                    float _a = 0.2f, float _b = 0.1f);
    ~Result();

private:
    Ui::Result *ui;
    QCustomPlot *customPlot;
    QVector<double> *times;
    void drawPlot(QVector<double> *sizes, QVector<double> *distances, float a, float b);
    double standardDeviation();
    double meanDifference();
    double confidenceRange();
    double standardError();
    double fittsLaw(QVector<double> *distances, QVector<double> sizes, double a, double b);
    double getMin(QVector<double> *vector);
    double getMax(QVector<double> *vector);

};

#endif // RESULT_H
