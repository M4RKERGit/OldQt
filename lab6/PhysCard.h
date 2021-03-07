#ifndef PHYSCARD_H
#define PHYSCARD_H
#include <QtCore>


class PhysCard
{
    Q_GADGET
public:
    PhysCard();
    QString number, date, pin, fio;
    float balance;
};

Q_DECLARE_METATYPE(PhysCard)

#endif // PHYSCARD_H
