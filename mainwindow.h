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
    void store_to_session();
    void get_from_session();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
