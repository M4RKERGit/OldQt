#ifndef CARD_H
#define CARD_H

#include <QMainWindow>
#include <QPainter>
#include <QPalette>
#include <QtGui>
#include "mainwindow.h"
#include "PhysCard.h"


namespace Ui {
class Card;
}

class Card : public QMainWindow
{
    Q_OBJECT

public:
    explicit Card(QWidget *parent = nullptr);
    ~Card();

public slots:
    void receiveData(PhysCard to_work);
    void on_buy_smth_triggered();
    void on_balance_triggered();
    void on_is_working_triggered();
    void on_returnbuy_triggered();
    void on_work_end_triggered();


signals:
    void return_back(PhysCard result);

private slots:

private:
    Ui::Card *ui;
    QPalette palette;
};
#endif // CARD_H
