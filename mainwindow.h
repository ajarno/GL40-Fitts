#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <target.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_quitter_clicked();

    void on_pushButton_demarrer_clicked();

private:
    Ui::MainWindow *ui;
    Target* target;
};

#endif // MAINWINDOW_H
