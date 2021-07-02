#include "prey.h"
#include "predator.h"
#include "grass.h"

#include <QtMath>
#include <QRandomGenerator>

prey::prey(QObject *parent) : QObject(parent)
{

}

QGraphicsEllipseItem* prey::get_animal() //геттер для графического элемента
{
    return animal;
}

double prey::check_distance(class grass *area_piece) //рассчет расстояния до травы
{
    double x_dist = 0;
    double y_dist = 0;
    x_dist = get_x() - area_piece->get_area()->x();
    y_dist = get_y() - area_piece->get_area()->y();
    return qSqrt(x_dist * x_dist + y_dist * y_dist);
}

double prey::get_x() //геттер для координаты x
{
    return animal->pos().x();
}

double prey::get_y() //геттер для координаты y
{
    return animal->pos().y();
}

int prey::get_courage() //геттер для смелости
{
    return courage;
}

int prey::get_stamina() //геттер для выносливости
{
    return stamina;
}

int prey::get_status() //геттер для статуса
{
    return status;
}

void prey::set_status(int status) //сеттер для статуса
{
    this->status = status;
}

void prey::set_animal(QGraphicsEllipseItem * animal) //сеттер для графического элемета
{
    this->animal = animal;
}

void prey::eat(class grass *field) //поедание травы
{
    if(stamina<100)
        stamina+=10;
    else
        stamina=100;
    field->vanish();
}

prey::~prey() //деструктор
{

}
