#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtMath>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double side_a = ui->side_1->value();
    double side_b = ui->side_2->value();
    const double ONE_DEGREE_IN_RADIANS = 0.017;
    double conor = ui->conor->text().toDouble();
    if(ui->radians->isChecked())
    {
        conor /= ONE_DEGREE_IN_RADIANS;
    };
    double compute = pow(side_a,2) + pow(side_b,2) - (2 * side_a * side_b * qCos(conor));
    double result = static_cast<int>(sqrt(compute));
    ui->result->setText(QString::number(result));
}

