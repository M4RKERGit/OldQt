#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

QVector<QString> wrd;
QVector<QString> trl;
int r = 0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file1("D:\\Qt\\Proj\\Lab4\\Lab4\\Words.txt");
    QFile file2("D:\\Qt\\Proj\\Lab4\\Lab4\\Translation.txt");
    srand(time(0));

    if ((file1.exists())&&(file1.open(QIODevice::ReadOnly)))
    {
        for (unsigned int i = 0; i < 20; i++)
        {
            wrd.push_back(file1.readLine());
            ui -> textBrowser->append(wrd[i]);
        }
    }
    file1.close();

    if ((file2.exists())&&(file2.open(QIODevice::ReadOnly)))
    {
        for (unsigned int i = 0; i < 20; i++)
        {
            trn.push_back(file2.readLine());
            ui -> textBrowser->append(trn[i]);
        }
    }
    file2.close();

    dwrd = wrd;


/*   unsigned int i=0;
    unsigned int nm=1;
    if ((file1.exists())&&(file1.open(QIODevice::ReadOnly)))
    {
        while((i<nm)&&(!file1.atEnd()))
        {
            file1.readLine();
            i++;
        }
        ui->W->setText(file1.readLine());
        file1.close();
    }
*/
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_DRem_clicked()
{
    ui -> TW -> setText("-");
    if (except.size() == wrd.size())
    {
        QMessageBox::information(this,
                                 "Уведомление",
                                 "Вы прогортали все слова, возврат к дефолту",
                                 QMessageBox::Ok);
        except.clear();
        ui -> TW -> setText("-");
        wrd.clear();
        wrd = dwrd;
    }
    bool replay = true;
    while (replay == true)
    {
        replay = false;
        rng = wrd.size();
        r = rand() %rng;
        for (int i = 0; i < except.size(); i++)
        {
            if (except[i] == r)
            {
                replay = true;
                break;
            }
        }
    }

    ui -> W -> setText(wrd[r]);
    except.push_back(r);
    string add = to_string(r);
    QString Add = QString::fromStdString(add);
    ui -> textEdit -> append(Add);
}

void MainWindow::on_Trans_clicked()
{
    if ((ui -> W->text())!="")
    {
        ui -> TW -> setText(trn[r]);
    }
}

void MainWindow::on_Rem_clicked()
{
    ui -> TW ->setText("-");
    dwrd.erase(dwrd.begin() + r);
    rwrd.push_back(wrd[r]);

    if (except.size() == wrd.size())
    {
        QMessageBox::information(this,
                                 "Уведомление",
                                 "Вы прогортали все слова, возврат к дефолту",
                                 QMessageBox::Ok);
        except.clear();
        ui -> TW -> setText("-");
    }
    bool replay = true;
    while (replay == true)
    {
        replay = false;
        rng = wrd.size();
        r = rand() %rng;
        for (int i = 0; i < except.size(); i++)
        {
            if (except[i] == r)
            {
                replay = true;
                break;
            }
        }
    }

    ui -> W -> setText(wrd[r]);
    except.push_back(r);
    string add = to_string(r);
    QString Add = QString::fromStdString(add);
    ui -> textEdit -> append(Add);
}

void MainWindow::on_start_clicked()
{
    if (except.size() == wrd.size())
    {
        QMessageBox::information(this,
                                 "Уведомление",
                                 "Вы прогортали все слова, возврат к дефолту",
                                 QMessageBox::Ok);
        except.clear();
        ui -> TW -> setText("");
    }
    bool replay = true;
    while (replay == true)
    {
        replay = false;
        rng = wrd.size();
        r = rand() %rng;
        for (int i = 0; i < except.size(); i++)
        {
            if (except[i] == r)
            {
                replay = true;
                break;
            }
        }
    }

    ui -> W -> setText(wrd[r]);
    except.push_back(r);
    string add = to_string(r);
    QString Add = QString::fromStdString(add);
    ui -> textEdit -> append(Add);
    ui -> start -> setVisible((false));
}
