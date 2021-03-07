#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QShortcut>
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>
#include <QTimer>
#include <QTime>
#include <QtGui>
#include <QFontDialog>
#include <QErrorMessage>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    keyCtrlD = new QShortcut(this);
    keyCtrlD->setKey(Qt::CTRL + Qt::Key_D);
    connect(keyCtrlD, SIGNAL(activated()), this, SLOT(slotShortcutCtrlD()));

    keyF11 = new QShortcut(this);
    keyF11->setKey(Qt::Key_F11);
    connect(keyF11, SIGNAL(activated()), this, SLOT(slotShortcutF11()));

    keyCtrlB = new QShortcut(this);
    keyCtrlB->setKey(Qt::CTRL + Qt::Key_B);
    connect(keyCtrlB, SIGNAL(activated()), this, SLOT(slotShortcutCtrlB()));

    ui->NUGGA->setVisible(false);



    ui->Answer1->setText("Доброго времени суток, вас приветствует\nАгент поддержки №666, чем могу помочь?");

    ui->Answer2->setText("Опишите вашу проблему в деталях");

    ui->Answer3->setText("Соединяю вас со специалистом по Вашему вопросу");

    ui->Answer4->setText("Подождите пару минут,");

    ui->Answer5->setText("Как Вы оцените нашу работу?");


    ui->textEdit->append("Сервер: Соединение с клиентом установлено");
    ui->textEdit->append("");

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Просто ввод
void MainWindow::on_pushButton_clicked()
{
    QString *buff = new QString;
    *buff = ui->lineEdit->text();
    if (*buff != "")
    {
        *buff = "Вы: " + ui->lineEdit->text();
        ui->textEdit->append(*buff);
        ui->textEdit->append("");
    }
    ui->lineEdit->clear();
}

void MainWindow::on_Answer1_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit->setText(ui->Answer1->text());
}

void MainWindow::on_Answer2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit->setText(ui->Answer2->text());
}

void MainWindow::on_Answer3_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit->setText(ui->Answer3->text());
}

void MainWindow::on_Answer4_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit->setText(ui->Answer4->text());
}

void MainWindow::on_Answer5_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit->setText(ui->Answer5->text());
}

void MainWindow::keyPressEvent( QKeyEvent * event )
{
    if(( event->key() == Qt::Key_Enter) || (event->key() == Qt::Key_Return))
    {
        qDebug()<< Qt::Key_Enter << "\n" <<  Qt::Key_Return;
        QString *buff = new QString;
        *buff = ui->lineEdit->text();
        if (*buff != "")
        {
            *buff = "Вы: " + ui->lineEdit->text();
            ui->textEdit->append(*buff);
            ui->textEdit->append("");
        }
        ui->lineEdit->clear();
    }
}

//Изменение текста шаблонов
void MainWindow::on_Edit1_clicked()
{
    ui->Answer1->setText(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void MainWindow::on_Edit2_clicked()
{
    ui->Answer2->setText(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void MainWindow::on_Edit3_clicked()
{
    ui->Answer3->setText(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void MainWindow::on_Edit4_clicked()
{
    ui->Answer4->setText(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void MainWindow::on_Edit5_clicked()
{
    ui->Answer5->setText(ui->lineEdit->text());
    ui->lineEdit->clear();
}

//Перемещение шаблонов
//Вверх
void MainWindow::on_U1_clicked()
{
    QString *buff = new QString;
    *buff = ui->Answer1->text();
    ui->Answer1->setText(ui->Answer5->text());
    ui->Answer5->setText(*buff);
    delete buff;
}

void MainWindow::on_U2_clicked()
{
    QString *buff = new QString;
    *buff = ui->Answer2->text();
    ui->Answer2->setText(ui->Answer1->text());
    ui->Answer1->setText(*buff);
    delete buff;
}

void MainWindow::on_U3_clicked()
{
    QString *buff = new QString;
    *buff = ui->Answer3->text();
    ui->Answer3->setText(ui->Answer2->text());
    ui->Answer2->setText(*buff);
    delete buff;
}

void MainWindow::on_U4_clicked()
{
    QString *buff = new QString;
    *buff = ui->Answer4->text();
    ui->Answer4->setText(ui->Answer3->text());
    ui->Answer3->setText(*buff);
    delete buff;
}

void MainWindow::on_U5_clicked()
{
    QString *buff = new QString;
    *buff = ui->Answer5->text();
    ui->Answer5->setText(ui->Answer4->text());
    ui->Answer4->setText(*buff);
    delete buff;
}

//Вниз
void MainWindow::on_D1_clicked()
{
    QString *buff = new QString;
    *buff = ui->Answer1->text();
    ui->Answer1->setText(ui->Answer2->text());
    ui->Answer2->setText(*buff);
    delete buff;
}

void MainWindow::on_D2_clicked()
{
    QString *buff = new QString;
    *buff = ui->Answer2->text();
    ui->Answer2->setText(ui->Answer3->text());
    ui->Answer3->setText(*buff);
    delete buff;
}

void MainWindow::on_D3_clicked()
{
    QString *buff = new QString;
    *buff = ui->Answer3->text();
    ui->Answer3->setText(ui->Answer4->text());
    ui->Answer4->setText(*buff);
    delete buff;
}

void MainWindow::on_D4_clicked()
{
    QString *buff = new QString;
    *buff = ui->Answer4->text();
    ui->Answer4->setText(ui->Answer5->text());
    ui->Answer5->setText(*buff);
    delete buff;
}

void MainWindow::on_D5_clicked()
{
    QString *buff = new QString;
    *buff = ui->Answer5->text();
    ui->Answer5->setText(ui->Answer1->text());
    ui->Answer1->setText(*buff);
    delete buff;
}

//Горячие клавиши
void MainWindow::slotShortcutCtrlD()
{
    ui->Answer1->setText("Доброго времени суток, вас приветствует\nАгент поддержки №666, чем могу помочь?");

    ui->Answer2->setText("Опишите вашу проблему в деталях");

    ui->Answer3->setText("Соединяю вас со специалистом по Вашему вопросу");

    ui->Answer4->setText("Подождите пару минут,");

    ui->Answer5->setText("Как Вы оцените нашу работу?");

    QMessageBox::information(this,
                             "Уведомление",
                             "Ваши шаблоны были сброшены на дефолтные",
                             QMessageBox::Ok);
}

void MainWindow::slotShortcutF11()
{
    ui->Answer1->setText("");

    ui->Answer2->setText("");

    ui->Answer3->setText("");

    ui->Answer4->setText("");

    ui->Answer5->setText("");

    QMessageBox::information(this,
                             "Уведомление",
                             "Ваши шаблоны были обнулены",
                             QMessageBox::Ok);
}

void MainWindow::slotShortcutCtrlB()
{

    if(player == nullptr)
    {
        QPixmap backgr("C:/Users/M4RKER/Downloads/63079455_p0.jpg");
        backgr = backgr.scaled(this->size(), Qt::IgnoreAspectRatio);
        palette.setBrush(QPalette::Window, backgr);

        player = new QMediaPlayer();
        player->setMedia(QUrl("C:/Users/M4RKER/Downloads/RipTear.mp3"));
    }

    if (hell == false)
    {
        this->setPalette(palette);
        player->play();
        hell = true;

        QMessageBox::information(this,
                                 "Осторожно!!!",
                                 "Вы открыли ацццкий чат",
                                 QMessageBox::Ok);
    }

    else
    {
        player->stop();
        this->setPalette(QPalette());
        hell = false;
        QMessageBox::information(this,
                                 "Уведомление",
                                 "В мире воцарилось спокойствие",
                                 QMessageBox::Ok);
    }
}


void MainWindow::on_NUGGA_pressed()
{
   Nig = new QMediaPlayer();
   Nig->setMedia(QUrl("C:/Users/M4RKER/Downloads/HEHE BOI.mp3"));
   Nig->play();
}

void MainWindow::on_NUGGA_released()
{
    Nig->stop();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    Nig = new QMediaPlayer();
    Nig->setMedia(QUrl("C:/Users/M4RKER/Downloads/HEHE BOI.mp3"));
    Nig->play();
    ui->NUGGA->setVisible(true);
    if (!find)
    {
        QMessageBox::information(this,
                                 "Уведомление",
                                 "Вы побеспокоили Ниггу, в наказание смените шрифт",
                                 QMessageBox::Ok);
        find = true;
    }

    bool bОк;
    QFont fnt = QFontDialog::getFont(&bОк);
    QApplication::setFont(fnt);
    if(!bOk) {
        // Была нажата кнопка Cancel
    }

}





void MainWindow::on_pushButton_2_clicked()
{
    int i = ui->comboBox->currentIndex();
    i++;
    ui->lineEdit->clear();
    switch (i)
    {
    case 1:
        ui->lineEdit->setText(ui->Answer3->text());
        break;
    case 2:
        ui->lineEdit->setText(ui->Answer4->text());
        break;
    case 3:
        ui->lineEdit->setText(ui->Answer5->text());
        break;
    case 4:
        ui->lineEdit->setText(ui->Answer1->text());
        break;
    case 5:
        ui->lineEdit->setText(ui->Answer2->text());
        break;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->Answer3->setText(ui->lineEdit->text());
    ui->lineEdit->clear();
}
