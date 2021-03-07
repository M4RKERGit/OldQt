#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir firpath(fromDir);
    QDir secpath(toDir);
    if(!secpath.exists()){    /* if directory don't exists, build it */
        if(!secpath.mkdir(secpath.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = firpath.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    /* if it is directory, copy recursively*/
            if(!copyDirectoryFiles(fileInfo.filePath(),
                secpath.filePath(fileInfo.fileName()),
                coverFileIfExist))
                return false;
        }
        else

        {            /* if coverFileIfExist == true, remove old file first */
            if(coverFileIfExist && secpath.exists(fileInfo.fileName()))
            {
                secpath.remove(fileInfo.fileName());
            }

            // files copy
            if(!QFile::copy(fileInfo.filePath(),
                secpath.filePath(fileInfo.fileName())))
            {
                    return false;
            }
        }
    }
    return true;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    ui -> itemlistfrom -> setVisible(false);
    ui -> itemlistto -> setVisible(false);


    QPixmap backgr("C:/Users/M4RKER/Downloads/матрица.png");
    backgr = backgr.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, backgr);
    this->setPalette(palette);

    ui -> path1 ->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 8, 8);"));
    ui -> path2 ->setStyleSheet(QString::fromUtf8("background-color: rgb(45, 51, 214);"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_path1_clicked()
{
    firpath = QFileDialog::getExistingDirectory(0, "Выбор папки", "");
    ui->pathName1->setText(firpath);
}

void MainWindow::on_path2_clicked()
{
    secpath = QFileDialog::getExistingDirectory(0, "Выбор папки", "");
    ui->pathName2->setText(secpath);
}


void MainWindow::refreshInfo()
{
    ui -> itemlistfrom -> setText("");
    ui -> itemlistto -> setText("");
    firlist.clear();
    seclist.clear();

    firlist.append("---------------------------------------------------------");
    firlist.append("                        ПАПКИ");
    firlist.append("---------------------------------------------------------");
    firlist += QDir(firpath).entryList(QDir::Dirs);

    seclist.append("---------------------------------------------------------");
    seclist.append("                        ПАПКИ");
    seclist.append("---------------------------------------------------------");
    seclist += QDir(secpath).entryList(QDir::Dirs);

    firlist.removeOne(".");
    seclist.removeOne(".");

    firlist.removeOne("..");
    seclist.removeOne("..");

    foreach(QString itemname, firlist)
    {
        itemname = "*" + itemname;
    }

    foreach(QString itemname, seclist)
    {
        itemname = "*" + itemname;
    }

    firlist.append("---------------------------------------------------------");
    firlist.append("                        ФАЙЛЫ");
    firlist.append("---------------------------------------------------------");
    firlist += QDir(firpath).entryList(QDir::Files);

    seclist.append("---------------------------------------------------------");
    seclist.append("                        ФАЙЛЫ");
    seclist.append("---------------------------------------------------------");
    seclist += QDir(secpath).entryList(QDir::Files);


    foreach(QString curstr, firlist)
    {
        ui -> itemlistfrom -> append(curstr);
        ui -> itemlistfrom -> append("");
    }

    foreach(QString curstr, seclist)
    {
        ui -> itemlistto -> append(curstr);
        ui -> itemlistto -> append("");
    }
}

void MainWindow::on_refreshbutt_clicked()
{
    refreshInfo();
    ui -> itemlistto -> setVisible(true);
    ui -> itemlistfrom -> setVisible(true);
}

void MainWindow::on_sync_clicked()
{
    foreach(QString word1, firlist)
    {
        if(!seclist.contains(word1, Qt::CaseInsensitive))
            {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, QString::fromUtf8("Сообщение"),
                QString::fromUtf8("Скопировать из ") + firpath  +
                QString::fromUtf8(" файл/*папку ") +word1 + QString::fromUtf8(" ?"),
                QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

                if (reply == QMessageBox::Yes)
                {
                    if(word1[0]=="*")
                    {
                    word1.remove(0,1);
                    copyDirectoryFiles(firpath+"/"+word1,secpath+"/"+word1,true);
                    continue;
                    }

                    QFile::copy(firpath+"/"+word1,secpath+"/"+word1);
                }
                else if (reply == QMessageBox::No)
                    continue;
                else
                    continue;
             }
    }


    foreach(QString word2, seclist)
    {
        if(!seclist.contains(word2, Qt::CaseInsensitive))
            {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, QString::fromUtf8("Сообщение"),
                QString::fromUtf8("Скопировать из ") + firpath  +
                QString::fromUtf8(" файл/*папку ") + word2 + QString::fromUtf8(" ?"),
                QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

                if (reply == QMessageBox::Yes)
                {
                    if(word2[0]=="*")
                    {
                    word2.remove(0,1);
                    copyDirectoryFiles(firpath+"/"+ word2,secpath+"/"+word2,true);
                    continue;
                    }

                    QFile::copy(firpath+"/"+word2,secpath+"/"+word2);
                }
                else if (reply == QMessageBox::No)
                    continue;
                else
                    continue;
             }
    }
    refreshInfo();
}

void MainWindow::on_By_triggered()
{
    QMessageBox::information(this,
                             "Авторы сего самовара говна",
                             "(ТМ)Спустя рукава геймс\nПамяти Сержа Дур-Дачника",
                             QMessageBox::Ok);
}
