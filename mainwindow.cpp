#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <QMap>
#include <QString>

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
void MainWindow::set_my_wares(QString &target, QString &price)
{
    MainWindow::myWaresMap.insert(target, price);
}
void MainWindow::get_my_wares()
{
    for(auto e : MainWindow::myWaresMap.toStdMap())
    {
      qDebug() << e.first << "," << e.second << '\n';
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString target, price;
    target = QString(ui->lineEdit->text());
    price = QString(ui->lineEdit_2->text());
    set_my_wares(target, price);
    get_my_wares();
}



void MainWindow::on_lineEdit_editingFinished()
{


}
