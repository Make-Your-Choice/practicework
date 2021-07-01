#include "prey.h"
#include "predator.h"
#include "grass.h"

#include <QtMath>
#include <QRandomGenerator>

prey::prey(QObject *parent) : QObject(parent)
{

}

QGraphicsEllipseItem* prey::get_animal()
{
    return animal;
}

double prey::check_distance(class grass *area_piece)
{
    double x_dist = 0;
    double y_dist = 0;
    x_dist = get_x() - area_piece->get_area()->x();
    y_dist = get_y() - area_piece->get_area()->y();
    return qSqrt(x_dist * x_dist + y_dist * y_dist);
}

double prey::get_x()
{
    return animal->pos().x();
}

double prey::get_y()
{
    return animal->pos().y();
}

int prey::get_courage()
{
    return courage;
}

int prey::get_stamina()
{
    return stamina;
}

int prey::get_status()
{
    return status;
}

void prey::set_status(int status)
{
    this->status = status;
}

void prey::set_animal(QGraphicsEllipseItem * animal)
{
    this->animal = animal;
}

void prey::eat(class grass *field)
{
    if(stamina<100)
        stamina+=10;
    else
        stamina=100;
    field->vanish();
}

prey::~prey()
{

}
