#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>
#include <QPalette>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
    void refreshInfo();
    ~MainWindow();

private slots:
    void on_path1_clicked();

    void on_path2_clicked();

    void on_refreshbutt_clicked();

    void on_sync_clicked();

    void on_By_triggered();
private:
    QString firpath = "";
    QString secpath = "";
    QStringList firlist;
    QStringList seclist;
    Ui::MainWindow *ui;
    QPalette palette;
};
#endif // MAINWINDOW_H
