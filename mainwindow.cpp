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
    private:
        QMap <QString, QString> myMap;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString target, price;
    target = QString(ui->lineEdit->text());
    price = QString(ui->lineEdit_2->text());
    qDebug("%s",qPrintable(target));
    qDebug("%s",qPrintable(price));
}

void MainWindow::on_lineEdit_editingFinished()
{


}
