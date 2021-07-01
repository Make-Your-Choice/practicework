#ifndef PREY_H
#define PREY_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsEllipseItem>

class prey : public QObject
{
    Q_OBJECT
public:
    explicit prey(QObject *parent = nullptr);
protected:
    int courage;
    int stamina;
    int status;
    QGraphicsEllipseItem *animal;
public:
    double check_distance(class grass *area_piece);
    double get_x();
    double get_y();
    int get_courage();
    int get_stamina();
    int get_status();
    QGraphicsEllipseItem* get_animal();
    void set_status(int status);
    void set_animal (QGraphicsEllipseItem *animal);
    void eat(class grass *field);
    virtual void fight() = 0;
    ~prey();
signals:

};

#endif // PREY_H
