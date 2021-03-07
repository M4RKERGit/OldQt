#include "mainwindow.h"
#include "card.h"
#include "ui_card.h"
#include <QInputDialog>
#include <QListWidget>
#include <QMessageBox>


Card::Card(QWidget *parent) : QMainWindow(parent), ui(new Ui::Card)
{
    ui->setupUi(this);
    QPixmap backgr("C:/Users/M4RKER/Downloads/Vozmak.png");
    backgr = backgr.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, backgr);
    this->setPalette(palette);

    ui->balance_info->setVisible(false);
    ui->PIN->setVisible(false);
    ui->base_balance->setVisible(false);

    QVector<Goods> goods;

    Goods g1, g2, g3, g4, g5;
    g1.name = "Репетиция";
    g1.cost = 1500;
    g2.name = "Яндекс Плюс";
    g2.cost = 59.90;
    g3.name = "Поездка домой";
    g3.cost = 678;
    g4.name = "Поход в Ашан";
    g4.cost = 312.50;
    g5.name = "Оплата общаги";
    g5.cost = 3264.76;
    goods.push_back(g1);
    goods.push_back(g2);
    goods.push_back(g3);
    goods.push_back(g4);
    goods.push_back(g5);
}

Card::~Card()
{
    delete ui;
}

void Card::on_buy_smth_triggered()
{
    QStringList items;
    int choice;
    float new_amount = 0;
    items << QString::fromUtf8("Репецития - 1500р.") << QString::fromUtf8("Яндекс+ - 59,90")  << QString::fromUtf8("Поезд домой - 678") << QString::fromUtf8("Поход в Ашан - 312,50") << QString::fromUtf8("Оплатить общагу - 3264,76");

    bool ok;
    QString item = QInputDialog::getItem(this,
                             QString::fromUtf8("Выберите покупку"),
                             QString::fromUtf8("Товар:"), items, 1, false, &ok);
    if (!ok)
    {
        return;
    }
    if (item == "Репецития - 1500р.")
    {
        choice = 1;
    }

    if (item == "Яндекс+ - 59,90")
    {
        choice = 2;
    }

    if (item == "Поезд домой - 678")
    {
        choice = 3;
    }

    if (item == "Поход в Ашан - 312,50")
    {
        choice = 4;
    }

    if (item == "Оплатить общагу - 3264,76")
    {
        choice = 5;
    }

    switch(choice)
    {
    case 1:
        new_amount = (ui->balance_info->text().toFloat()) - 1500;
        if (new_amount < 0)
        {
            QMessageBox::about(this, "Ошибка", "Вы слишком бомж, отмена покупки");
        }
        else
        {
            ui->balance_info->setText(QString::number(new_amount));
            QMessageBox::about(this, "Готово!", "Покупка совершена, приятного пользования");
        }
        break;
    case 2:
        new_amount = (ui->balance_info->text().toFloat()) - 59.90;
        if (new_amount < 0)
        {
            QMessageBox::about(this, "Ошибка", "Вы слишком бомж, отмена покупки");
        }
        else
        {
            ui->balance_info->setText(QString::number(new_amount));
            QMessageBox::about(this, "Готово!", "Покупка совершена, приятного пользования");
        }
        break;
    case 3:
        new_amount = (ui->balance_info->text().toFloat()) - 678;
        if (new_amount < 0)
        {
            QMessageBox::about(this, "Ошибка", "Вы слишком бомж, отмена покупки");
        }
        else
        {
            ui->balance_info->setText(QString::number(new_amount));
            QMessageBox::about(this, "Готово!", "Покупка совершена, приятного пользования");
        }
        break;
    case 4:
        new_amount = (ui->balance_info->text().toFloat()) - 312.50;
        if (new_amount < 0)
        {
            QMessageBox::about(this, "Ошибка", "Вы слишком бомж, отмена покупки");
        }
        else
        {
            ui->balance_info->setText(QString::number(new_amount));
            QMessageBox::about(this, "Готово!", "Покупка совершена, приятного пользования");
        }
        break;
    case 5:
        new_amount = (ui->balance_info->text().toFloat()) - 3264.76;
        if (new_amount < 0)
        {
            QMessageBox::about(this, "Ошибка", "Вы слишком бомж, отмена покупки");
        }
        else
        {
            ui->balance_info->setText(QString::number(new_amount));
            QMessageBox::about(this, "Готово!", "Покупка совершена, приятного пользования");
        }
        break;
    }
}

void Card::on_balance_triggered()
{
    QMessageBox::about(this, "Состояние баланса", "Ваш баланс на данный момент:\n                    " + ui->balance_info->text() + "\n      Все не так уж и плохо!)");
}

void Card::on_is_working_triggered()
{
    if (ui->numlab->text().isEmpty() | ui->PIN->text().isEmpty() | ui->name->text().isEmpty() | ui->balance_info->text().isEmpty())
    {
        QMessageBox::about(this, "Состояние карты", "Данные карты явно повреждены, обратитесь в отдел по работе с клиентами по адресу: 24220, Каэдвен, Каэр Морхен, Северное крыло крепости");
    }
    else QMessageBox::about(this, "Состояние карты", "С Вашей картой всё хорошо, спасибо, что пользуетесь услугами\n ОАО 'Чианфанелли и Ко'");
}

void Card::on_returnbuy_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QString::fromUtf8("Сообщение"),
                          QString::fromUtf8("Вы уверены, что хотите вернуть все оформленные покупки и подписки за этот сеанс? Комисиия за возврат - 100 у.е"),
                          QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        ui->balance_info->setText(QString::number((ui->base_balance->text()).toFloat() - 100));
        ui->base_balance->setText(ui->balance_info->text());
    }

    else if (reply == QMessageBox::No)
    {
        return;
    }
}

void Card::on_work_end_triggered()
{
    PhysCard result;
    result.fio = ui->name->text();
    result.pin = ui->PIN->text();
    QString date = ui->valid->text();
    date.remove(0,12);
    result.date = date;
    result.number = ui->numlab->text();
    result.balance = ((ui->balance_info->text()).toFloat());
    emit return_back(result);
    int n = 2000;
    QProgressDialog* pprd = new QProgressDialog("Сохраняю результаты сеанса...", "&Отмена", 0, n);
    pprd->setMinimumDuration(0);
    pprd->setWindowTitle("Пожалуйста, ждите...");
    for (int i = 0; i < n; ++i)
    {
        pprd->setValue(i) ;
        qApp->processEvents();
        if (pprd->wasCanceled())
        {
             break;
        }
    }
    pprd->setValue(n) ;
    delete pprd;
    this->close();
}

void Card::receiveData(PhysCard to_work)
{
    ui->numlab->setText(to_work.number);
    ui->valid->setText("Valid thru: " + to_work.date);
    ui->name->setText(to_work.fio);
    ui->PIN->setText(to_work.pin);
    ui->balance_info->setText(QString::number(to_work.balance));
    ui->base_balance->setText(QString::number(to_work.balance));
}
