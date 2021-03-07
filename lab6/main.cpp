#include "mainwindow.h"
#include "Goods.h"
#include "PhysCard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<Goods>();
    qRegisterMetaType<PhysCard>();
    MainWindow w;
    w.show();
    return a.exec();
}
