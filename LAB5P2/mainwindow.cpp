#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap backgr("C:/Users/M4RKER/Downloads/школяр.jpg");
        backgr = backgr.scaled(this->size(), Qt::IgnoreAspectRatio);
        palette.setBrush(QPalette::Window, backgr);
        this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Выберите файл..."), "", tr("Текстовые файлы (*.txt)"));

    if (!fileName.isEmpty())
    {
       ui->lineEdit->setText(fileName);
    }

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("%1").arg("Текстовый редактор"),
                             tr("Не могу открыть файл %1\nПричина: %2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream in(&file);

    ui->textEdit->setText(in.readAll());

}

void MainWindow::on_replaceButton_clicked()
{
    QRegularExpression exp(ui->lineEdit_2->text());
    QString str =ui->textEdit->toPlainText();
    str.replace(exp, ui->lineEdit_3->text());
    ui->textEdit->setText(str);
}

void MainWindow::on_saveButton_clicked()
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("%1").arg("myName"),
                             tr("Не могу сохранить файл %1\nПричина: %2.")
                             .arg(fileName)
                             .arg(file.errorString()));
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
}

void MainWindow::on_searchButton_clicked()
{
    QString findmask = ui->lineEdit_2->text();
    QRegularExpression re(findmask);
    QString endStr = re.match(ui->textEdit->toPlainText()).capturedTexts().join(' ');

    if(!endStr.isEmpty())
    {
        QMessageBox::warning(this, tr("%1").arg(""), "Текст по маске "+ findmask + " найден!" );
    }
    else
        QMessageBox::warning(this, tr("%1").arg(""), "Текст по маске "+ findmask + " не найден!" );

}
