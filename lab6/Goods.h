#ifndef GOODS_H
#define GOODS_H
#include <QtCore>


class Goods
{
    Q_GADGET
public:
    Goods();
    QString name;
    double cost;
};

Q_DECLARE_METATYPE(Goods)

#endif // GOODS_H
