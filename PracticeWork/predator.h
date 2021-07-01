#ifndef PREDATOR_H
#define PREDATOR_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>

class predator : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    explicit predator(QObject *parent = nullptr);
private:
    int hunger;
    int stamina;
    QGraphicsEllipseItem *animal;
public:
    double check_distance(class prey *animal_single);
    double get_x();
    double get_y();
    int get_hunger();
    int get_stamina();
    QGraphicsEllipseItem* get_animal();
    void set_position(double x, double y);
    void hunt();
    void eat(class zebra *animal);
    void eat(class buffalo *animal);
    void damage();
    void damage(int horns);
    void rest();
    ~predator();
signals:
};

#endif // PREDATOR_H
