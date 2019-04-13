#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent, QVector<double> *_sizes, QVector<double> *_distances, QVector<double> *_times, float _a, float _b):
    QWidget (parent),
    ui(new Ui::Result),
    times(_times)
{
    ui->setupUi(this);
    drawPlot(_sizes,_distances,_a,_b);
    fillLabels();
}

Result::~Result()
{
    delete ui;
}

void Result::drawPlot(QVector<double> *sizes, QVector<double> *distances, float a, float b)
{
    QVector<double> *nb_cibles = new QVector<double>();
    for (int i = 1; i <= 10; ++i) {
        nb_cibles->append(i);
    }

    customPlot = new QCustomPlot(this);
    customPlot->setGeometry(0,0,width(),height()/2);

    customPlot->addGraph(customPlot->xAxis,customPlot->yAxis);
    customPlot->addGraph(customPlot->xAxis,customPlot->yAxis);
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setData(*nb_cibles, *times);

    customPlot->graph(1)->setPen(QPen(Qt::red));
    customPlot->graph(1)->setData(*nb_cibles, *fittsLaw(distances, sizes, a, b));

    customPlot->xAxis->setLabel("Numéro de l'essai");
    customPlot->yAxis->setLabel("Temps (ms)");

    customPlot->xAxis->setRange(getMin(nb_cibles), getMax(nb_cibles));

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 0; i < nb_cibles->length(); i++) {
        textTicker->addTick(nb_cibles->value(i),"Taille : " + QString::number(sizes->value(i))
                            + "\nDistance : " + QString::number(distances->value(i)));
    }
    textTicker->setSubTickCount(getMax(nb_cibles));
    customPlot->xAxis->setTicker(textTicker);

    customPlot->yAxis->setRange(getMin(times),getMax(times));

    customPlot->replot();

}

void Result::fillLabels()
{
    ui->error_label->setNum(standardError());
    ui->deviation_label->setNum(standardDeviation());
    ui->mean_diff_label->setNum(meanDifference());
    ui->confidence_label->setNum(confidenceRange());
}

double Result::standardDeviation()
{
    double variance(0);

    for (int i = 0; i < times->length(); i++) {
        variance += pow(times->value(i) - mean(),2);
    }

    return sqrt(variance/times->length());
}

double Result::meanDifference()
{
    QVector<double> *diff = new QVector<double>();
    double mean(0);

    for (int i = 0; i < times->length() - 1; i++) {
        diff->append((times->value(i) + times->value(i+1))/2);
    }

    for (int i = 0; i < diff->length(); i++) {
        mean += diff->value(i);
    }

    return mean/diff->length();
}

double Result::confidenceRange()
{
    return mean()-1.96*standardError();
}

double Result::standardError()
{
    return standardDeviation()/sqrt(mean());
}

double Result::mean()
{
    double m(0);

    for (int i = 0; i < times->length(); i++) {
        m += times->value(i);
    }

    return m/times->length();
}

QVector<double> *Result::fittsLaw(QVector<double> *distances, QVector<double> *sizes, double a, double b)
{
    QVector<double> *fitts_result = new QVector<double>();
    for (int i = 0; i < sizes->length(); i++) {
        fitts_result->append(a+b*log2((distances->value(i)/sizes->value(i))+1));
    }
    return fitts_result;
}

double Result::getMin(QVector<double> *vector)
{
    return *std::min_element(vector->constBegin(),vector->constEnd());
}

double Result::getMax(QVector<double> *vector)
{
    return *std::max_element(vector->constBegin(),vector->constEnd());
}
