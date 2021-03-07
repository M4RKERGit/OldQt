#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cards->setEditTriggers( QAbstractItemView :: NoEditTriggers );

    srand(time(NULL));

    names.push_back("Alexander");
    names.push_back("John");
    names.push_back("Victor");
    names.push_back("Fred");
    names.push_back("Jotaro");
    names.push_back("Joseph");
    names.push_back("Josuke");
    names.push_back("Giorno");
    names.push_back("Trish");
    names.push_back("Erina");
    names.push_back("Robert");
    names.push_back("Rudolf");
    names.push_back("Gans");

    fam.push_back("Bucelatti");
    fam.push_back("Kujo");
    fam.push_back("Joestar");
    fam.push_back("fon Stroheim");
    fam.push_back("Giovanna");
    fam.push_back("Anderson");
    fam.push_back("Floyd");
    fam.push_back("Higashikata");
    fam.push_back("Brando");
    fam.push_back("Polnareff");
    fam.push_back("Hirose");
    fam.push_back("Zeppeli");
    fam.push_back("Nijimura");

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::random4int()
{
    int buff;
    QString ret;
    for (unsigned int i = 0; i < 4; i++)
    {
        buff = rand() % 9;
        ret = ret + QString::number(buff);
    }
    return ret;
}

float MainWindow::randomfloat()
{
    float ret, one, two;
    one = rand() % 10000;
    two = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    ret = one + two;
    return ret;
}

QString MainWindow::randomdate()
{
    QString mon, year;
    unsigned int m = 1 + rand() % 11;
    if (m < 10)
    {
        mon = "0" + QString::number(m);
    }
    else mon = QString::number(m);
    unsigned int y = 20 + rand() % 5;
    year = QString::number(y);
    QString ret = mon + "/" + year;
    return ret;
}

QString MainWindow::randomname()
{
    QString n, f;
    n = names[rand() % (names.size())];
    f = fam[rand() % (fam.size())];
    QString ret = n + " " + f;
    return ret;
}

void MainWindow::on_newcard_clicked()
{
    ui->cards->clearSelection();
    qint32 last_row = ui->cards->rowCount();
    ui->cards->insertRow(last_row);
    QString buffst = random4int()+" "+random4int()+" "+random4int()+" "+random4int();
    float bufffl = randomfloat();
    QString buffdate = randomdate();
    QString buffpin = random4int();
    QString bufffio = randomname();
    QTableWidgetItem *pan = new QTableWidgetItem(buffst);
    QTableWidgetItem *balance = new QTableWidgetItem(QString::number(bufffl));
    QTableWidgetItem *m_y = new QTableWidgetItem(buffdate);
    QTableWidgetItem *pin = new QTableWidgetItem(buffpin);
    QTableWidgetItem *name = new QTableWidgetItem(bufffio);
    ui->cards->setItem( last_row, 0, pan );
    ui->cards->setItem( last_row, 1, balance );
    ui->cards->setItem( last_row, 2, m_y );
    ui->cards->setItem( last_row, 3, pin );
    ui->cards->setItem( last_row, 4, name );

    PhysCard card_add;
    card_add.number = buffst;
    card_add.balance = bufffl;
    card_add.date = buffdate;
    card_add.pin = buffpin;
    card_add.fio = bufffio;
    list.push_back(card_add);

    cd = QDate::currentDate();
    ct = QTime::currentTime();
    QString toadd = cd.toString(Qt::LocaleDate) + " | " + ct.toString() + " | Добавлена новая карта";
    ui->history->addItem(toadd);
}

void MainWindow::on_delcard_clicked()
{
    if (ui->cards->selectionModel()->hasSelection())
        {
            ui->cards->removeRow(ui->cards->selectedItems()[0]->row());
            cd = QDate::currentDate();
            ct = QTime::currentTime();
            QString toadd = cd.toString(Qt::LocaleDate) + " | " + ct.toString() + " | Удалена карта";
            ui->history->addItem(toadd);
            unsigned int number = (ui->cards->currentRow())+1;
            list.erase(list.begin() + number);
        }
}

void MainWindow::on_clear_history_clicked()
{
    ui->history->clear();
}

void MainWindow::on_startform2_clicked()
{
    if (ui->cards->selectionModel()->hasSelection())
        {
        numtow = (ui->cards->currentRow()) - 1;
        int n = 2000;
        QProgressDialog* pprd = new QProgressDialog("Получаю доступ к карте...", "&Отмена", 0, n);
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
        Card *ww = new Card;
        ww->show();
        connect(this, SIGNAL(sendData(PhysCard)), ww, SLOT(receiveData(PhysCard)));
        connect(ww, SIGNAL(return_back(PhysCard)), this, SLOT(getcardback(PhysCard)));
        PhysCard to_work = list[numtow + 1];
        emit sendData(to_work);
        }
}

void MainWindow::getcardback(PhysCard result)
{
    list[numtow + 1].fio = result.fio;
    list[numtow + 1].pin = result.pin;
    list[numtow + 1].date = result.date;
    list[numtow + 1].number = result.number;
    list[numtow + 1].balance = result.balance;

    QTableWidgetItem *pan = new QTableWidgetItem(result.number);
    QTableWidgetItem *balance = new QTableWidgetItem(QString::number(result.balance));
    QTableWidgetItem *m_y = new QTableWidgetItem(result.date);
    QTableWidgetItem *pin = new QTableWidgetItem(result.pin);
    QTableWidgetItem *name = new QTableWidgetItem(result.fio);
    ui->cards->setItem(numtow, 5, pan);
    ui->cards->setItem(numtow, 6, balance);
    ui->cards->setItem(numtow, 7, m_y);
    ui->cards->setItem(numtow, 8, pin);
    ui->cards->setItem(numtow, 9, name);
}
