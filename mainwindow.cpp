#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_quitter_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_demarrer_clicked()
{
    target = new Target(nullptr, ui->spinBox_nb->value(), ui->spinBox_taille_min->value(), ui->spinBox_taille_max->value());
    target->show();
}
