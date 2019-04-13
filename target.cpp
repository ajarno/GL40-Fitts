#include "target.h"
#include "ui_target.h"

Target::Target(QWidget *parent, int _nb_cibles, int _t_min, int _t_max, float _a, float _b) :
    QWidget(parent),
    ui(new Ui::Target),
    nb_cibles(_nb_cibles),
    t_min(_t_min),
    t_max(_t_max),
    a(_a),
    b(_b)
{
    ui->setupUi(this);

    ui->label_nb_restant->setNum(nb_cibles);

    beginButton = new BeginButton(ui->graphicsView);
    connect(beginButton, SIGNAL(clicked()), this, SLOT(beginTest()));

    randomButton = new RandomButton(ui->graphicsView, t_max, t_min);
    randomButton->hide();

    initAll();
}

Target::~Target()
{
    delete ui;
}

void Target::on_pushButton_retour_clicked()
{
    this->close();
}

void Target::on_pushButton_resultats_clicked()
{
    this->close();
    result = new Result(nullptr,sizes,distances,times,a,b);
    result->show();
}

void Target::beginTest()
{
    randomButton->show();
    connect(randomButton, SIGNAL(clicked()), this, SLOT(updateTest()));
    beginButton->close();

    time->start();
    distances->append(computeDistance());
}

void Target::updateTest()
{
    ui->label_nb_restant->setNum(--nb_cibles);

    if(nb_cibles > 0) {
        randomButton->updateMe();

    } else {
        randomButton->close();
        ui->pushButton_resultats->setEnabled(true);
        ui->pushButton_resultats->setStyleSheet("QPushButton {background-color: red; font-weight: bold; color: white}");
    }

    saveData();
}

double Target::computeDistance() {
    int xCible, yCible, xCurseur, YCurseur;
    double distance;

    xCible = randomButton->pos().x();
    yCible = randomButton->pos().y();

    xCurseur = this->cursor().pos().x();
    YCurseur = this->cursor().pos().y();

    distance = sqrt(pow(xCurseur - xCible,2)+pow(YCurseur - yCible,2));

    return distance;
}

void Target::initAll() {
    setMouseTracking(true);
    time = new QTime();
    times = new QVector<double>();
    distances = new QVector<double>();
    sizes = new QVector<double>();
}

void Target::saveData() {
    times->append(time->elapsed());
    time->restart();

    sizes->append(randomButton->getSize());

    distances->append(computeDistance());
}
