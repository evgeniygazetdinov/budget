#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <QMap>
#include <QString>




const QString SESSION_PATH = "/home/evgesha/budget/out.txt";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::fooling_table();
    qDebug()<<"HERE";

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

//TODO move session methods in indendent class
QString MainWindow::read_session()
{
    QByteArray data;
    QFile file(SESSION_PATH);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";

    QTextStream in(&file);
    // You could use readAll() here, too.
    while (!in.atEnd()) {
        QString line = in.readLine();
        data.append(line);
        //to do convert to qmap and put into screen
    }

    file.close();
    qDebug()<<data;
    return data;
}

void MainWindow::write_to_session()
{
    QFile file(SESSION_PATH);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Append))
        return;

    QTextStream out(&file);
    for(auto e : MainWindow::myWaresMap.keys())
    {
      out <<e<<" "<< MainWindow::myWaresMap.value(e)<<"\n";
    }

    file.close();
    qDebug()<<"writen`";
    QMap<QString, int> myMap;

}

void MainWindow::fooling_table()
{
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(3);

    /*add stuff inside the table view*/
    QString line = "hello";
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        for(int j=0; j<ui->tableWidget->columnCount(); j++)
        {
            QTableWidgetItem *pCell = ui->tableWidget->item(i, j);
            if(!pCell)
            {
                pCell = new QTableWidgetItem;
                ui->tableWidget->setItem(i, j, pCell);
            }
            pCell->setText(line);
        }
    }
}

void MainWindow::store_to_session()
{
    write_to_session();
    qDebug()<<"here`";

}
void MainWindow::get_from_session()
{

}


void MainWindow::on_pushButton_clicked()
{
    QString target, price;
    target = QString(ui->lineEdit->text());
    price = QString(ui->lineEdit_2->text());
    set_my_wares(target, price);
    store_to_session();
    read_session();
}


void MainWindow::on_lineEdit_editingFinished()
{


}
