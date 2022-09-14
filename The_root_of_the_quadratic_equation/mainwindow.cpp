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
  ui->message->clear();
  ui->result_1->clear();
  ui->result_2->clear();

double a = ui->factor_a->text().toDouble();
double b = ui->factor_b->text().toDouble();
double c = ui->factor_c->text().toDouble();

double discriminant = (pow(b, 2)) - 4*a*c;
if(discriminant < 0)
{
    ui->message->setText("У уравнения нет корней");
}
else if(discriminant == 0)
{
    ui->message->setText("У уравнения один корень");
    double result = (-b + (sqrt(discriminant)))/(2*a);
    ui->result_1->setText(QString::number(result));
    ui->result_2->setText("-");
}
else if (discriminant > 0 && a != 0)
{
     ui->message->setText("У уравнения два корня");
     double x_1 = (-b - (qSqrt(discriminant)))/(2*a);
     double x_2 = (-b + (qSqrt(discriminant)))/(2*a);
     ui->result_1->setText(QString::number(x_1));
     ui->result_2->setText(QString::number(x_2));
}
else if (discriminant > 0 && a == 0)
{   ui->message->setText("Это не квадратное уравнение с одним корнем");
    double x = -c / b;
    ui->result_1->setText(QString::number(x));
    ui->result_2->setText("-");
}
}

