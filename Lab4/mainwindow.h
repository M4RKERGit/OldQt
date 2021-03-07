#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QVector>
#include <QMessageBox>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_DRem_clicked();

    void on_Trans_clicked();

    void on_Rem_clicked();

    void on_start_clicked();

private:
    Ui::MainWindow *ui;
    int r;
    unsigned int rng;
    QVector <QString> wrd;
    QVector <QString> trn;
    QVector <int> except;
    QVector <QString> dwrd;
    QVector <QString> rwrd;
};


#endif // MAINWINDOW_H
