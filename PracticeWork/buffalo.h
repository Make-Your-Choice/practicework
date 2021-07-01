#ifndef BUFFALO_H
#define BUFFALO_H

#include <QMainWindow>
#include <QObject>
#include <prey.h>

class buffalo : public prey
{
    Q_OBJECT
public:
    explicit buffalo(QObject *parent = nullptr);
private:
    int horns_durability;
public:
    int get_horns_durability();
    void fight();
    ~buffalo();
signals:

};

#endif // BUFFALO_H
