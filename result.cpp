#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent, QVector<double> *_sizes, QVector<double> *_distances, QVector<double> *_times, float _a, float _b):
    QWidget (parent),
    ui(new Ui::Result),
    times(_times)
{
    ui->setupUi(this);
    drawPlot(_sizes,_distances,_a,_b);
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
    customPlot->setGeometry(0,0,1000,800);

    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(*nb_cibles, *times);

    // give the axes some labels:
    customPlot->xAxis->setLabel("Numéro de l'essai");
    customPlot->yAxis->setLabel("Temps (ms)");

    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(getMin(nb_cibles), getMax(nb_cibles));

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 0; i < nb_cibles->length(); i++) {
        textTicker->addTick(nb_cibles->takeAt(i),"Taille : " + QString::number(sizes->takeAt(i))
                            + "\nDistance : " + QString::number(distances->takeAt(i)));
    }
    textTicker->setSubTickCount(getMax(nb_cibles));
    customPlot->xAxis->setTicker(textTicker);

    customPlot->yAxis->setRange(getMin(times),getMax(times));
    customPlot->replot();

}

double Result::getMin(QVector<double> *vector)
{
    return *std::min_element(vector->constBegin(),vector->constEnd());
}

double Result::getMax(QVector<double> *vector)
{
    return *std::max_element(vector->constBegin(),vector->constEnd());
}
