#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextDocument>
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
    QString Our_text = ui->Text_window_1->toPlainText();
    ui->Text_window_2->insertPlainText(" " + Our_text);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString Our_text = ui->Text_window_1->toPlainText();
    ui->Text_window_1->clear();
    ui->Text_window_2->insertPlainText(" " + Our_text);
}


void MainWindow::on_pushButton_3_clicked()
{
    QString html = ui->HTML_code_window->toPlainText();
    ui->Text_window_2->insertPlainText(" ");
    ui->Text_window_2->setHtml(html);
}

