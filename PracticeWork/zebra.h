#ifndef ZEBRA_H
#define ZEBRA_H

#include <QMainWindow>
#include <QObject>
#include "prey.h"

class zebra : public prey
{
    Q_OBJECT
public:
    explicit zebra(QObject *parent = nullptr);
public:
    void fight();
    ~zebra();
signals:

};

#endif // ZEBRA_H
