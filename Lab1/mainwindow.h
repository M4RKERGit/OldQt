#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QTextEdit>
#include <windows.h>
#include <QKeyEvent>
#include <QMessageBox>


class QMediaPlayer;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool hell{false};
    bool bOk;
    bool find = false;



private slots:

    void slotShortcutCtrlD();
    void slotShortcutCtrlB();
    void slotShortcutF11();

    void on_pushButton_clicked();

    void keyPressEvent(QKeyEvent * event);

    void on_Answer1_clicked();

    void on_Answer2_clicked();

    void on_Answer3_clicked();

    void on_Answer4_clicked();

    void on_Answer5_clicked();

    void on_Edit1_clicked();

    void on_Edit2_clicked();

    void on_Edit3_clicked();

    void on_Edit4_clicked();

    void on_Edit5_clicked();

    void on_U1_clicked();

    void on_U2_clicked();

    void on_U3_clicked();

    void on_U4_clicked();

    void on_U5_clicked();

    void on_D1_clicked();

    void on_D2_clicked();

    void on_D3_clicked();

    void on_D4_clicked();

    void on_D5_clicked();

    void on_NUGGA_pressed();

    void on_NUGGA_released();

    void mouseDoubleClickEvent(QMouseEvent *event);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QShortcut   *keyCtrlD{nullptr};
    QShortcut   *keyCtrlB{nullptr};
    QShortcut   *keyF11{nullptr};
    QMediaPlayer* player{nullptr};
    QMediaPlayer* Nig{nullptr};
    QPalette palette;
};
#endif // MAINWINDOW_H
