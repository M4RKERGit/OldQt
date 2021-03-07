#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QSettings>
#include <QDateTime>
#include <QProgressDialog>
#include <card.h>

#include "Goods.h"
#include "PhysCard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class Card;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float randomfloat();
    QString random4int();
    QString randomdate();
    QString randomname();
    QVector<PhysCard> list;
    QVector<QString> names;
    QVector<QString> fam;
    QVector<Goods> goods;

    unsigned int numtow;

signals:
    void sendData(PhysCard to_work);

private slots:
    void on_newcard_clicked();
    void on_delcard_clicked();
    void on_clear_history_clicked();
    void on_startform2_clicked();
    void getcardback(PhysCard result);

private:
    Ui::MainWindow *ui;
    Ui::Card *ww;
    QDate cd;
    QTime ct;
};

#endif // MAINWINDOW_H
