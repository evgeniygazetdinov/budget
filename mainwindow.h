#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMap>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QMap <QString, QString> myWaresMap;
    void set_my_wares(QString &target, QString &price);
    void get_my_wares();
    QString read_session();
    void write_to_session();
    void store_to_session();
    void get_from_session();
    void fooling_table();
    void readJson();
    int find_quantity_good_from_session();
    void remove_values_from_file_by_row(int row_number);
    QString file_get_line(QString fullFileName,int linenr);


private slots:
    void on_pushButton_clicked();
    void clean_table();
    void on_lineEdit_editingFinished();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
