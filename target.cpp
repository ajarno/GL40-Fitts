#include "target.h"
#include "ui_target.h"

Target::Target(QWidget *parent, int _nb_cibles, int _t_min, int _t_max) :
    QWidget(parent),
    ui(new Ui::Target),
    nb_cibles(_nb_cibles),
    t_min(_t_min),
    t_max(_t_max)
{
    ui->setupUi(this);

    ui->label_nb_restant->setNum(nb_cibles);

    beginButton = new BeginButton(ui->graphicsView);
    connect(beginButton, SIGNAL(clicked()), this, SLOT(beginTest()));

    randomButton = new RandomButton(ui->graphicsView, t_max, t_min);
    randomButton->hide();
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

}

void Target::beginTest()
{
    randomButton->show();
    connect(randomButton, SIGNAL(clicked()), this, SLOT(updateTest()));
    beginButton->close();
}

void Target::updateTest()
{
    ui->label_nb_restant->setNum(--nb_cibles);

    if(nb_cibles > 0) {
        randomButton->updateMe();

    } else {
        randomButton->close();
    }
}
