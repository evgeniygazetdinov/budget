#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <QMap>
#include <QString>
#include <fstream>
#include <iostream>
#include <sstream>



const QString SESSION_PATH = "/home/evgesha/budget/out.txt";
const int COLUMN_COUNT = 2;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::fooling_table();
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
    if (!(file.open(QIODevice::WriteOnly | QIODevice::Append)))
        return;
    qDebug()<<"on write";
    QTextStream out(&file);
    for(auto e : MainWindow::myWaresMap.keys())
    {
      out <<e<<" "<< MainWindow::myWaresMap.value(e)<<"\n";
    }

    file.close();
    qDebug()<<"writen`";

}

int MainWindow::find_quantity_good_from_session()
{
    int numLines = 0;
    QFile inputFile(SESSION_PATH);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          numLines++;
       }
       inputFile.close();
    }
    return numLines;
}

void MainWindow::fooling_table()
{
    int row_count = find_quantity_good_from_session();
    ui->tableWidget->setRowCount(row_count);
    qDebug()<<row_count;
    ui->tableWidget->setColumnCount(COLUMN_COUNT);
    /*add stuff inside the table view*/
    QString line = "hello";

    QFile inputFile(SESSION_PATH);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
            for( int row = 0; row < row_count; row++ )
            {
                for( int column = 0; column < COLUMN_COUNT; column++ )
                {
                      QString line = in.readLine();
                      QStringList list = line.split(QRegExp("[\r\n\t ]+"), QString::SkipEmptyParts);
                      for ( const auto& i : list  )
                      {
                          QVariant oVariant = i;

                          QTableWidgetItem * poItem = new QTableWidgetItem();
                          poItem->setData( Qt::DisplayRole, oVariant );

                          ui->tableWidget->setItem( row, column, poItem );
                      }


                }
            }
       }
       inputFile.close();
    }
}

void MainWindow::remove_values_from_file_by_row(int row_number){
    QFile file(SESSION_PATH);
    int line_count=0;
    file.open(QIODevice::ReadOnly); //| QIODevice::Text)
    QString line[100];
    QTextStream in(&file);
    while( !in.atEnd())
    {
        line[line_count]=in.readLine();
        line_count++;
        if(line_count == row_number){
              qDebug()<<line_count;
        }


    }
}

void MainWindow::clean_table(){
    qDebug()<<"cleaning"<<ui->tableWidget->rowCount()<<"\n";
    while(ui->tableWidget->rowCount() > 0){
        ui->tableWidget->removeRow(0);
    }
}

void MainWindow::store_to_session()
{
    write_to_session();

}

void MainWindow::on_pushButton_clicked()
{
    QString target, price;
    target = QString(ui->lineEdit->text());
    price = QString(ui->lineEdit_2->text());
    set_my_wares(target, price);
    store_to_session();
    clean_table();
    fooling_table();
}


void MainWindow::on_lineEdit_editingFinished()
{


}

void MainWindow::on_pushButton_2_clicked()
{
    int row = ui->tableWidget->currentRow();

    ui->tableWidget->removeRow(row);
    remove_values_from_file_by_row(row);
}
