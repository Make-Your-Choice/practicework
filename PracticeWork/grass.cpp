#include "grass.h"

#include <QRandomGenerator>
#include <QPainter>


grass::grass(QObject *parent) : QObject(parent) //конструктор
{
    QRandomGenerator *gen = QRandomGenerator::global();
    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem();
    circle->setRect(60.0, 60.0, 100.0, 60.0);
    QBrush brush(QColor(121, 145, 13), Qt::Dense4Pattern);
    circle->setBrush(brush);
    QPen pen(Qt::transparent, 1, Qt::SolidLine);
    circle->setPen(pen);
    circle->setPos(gen->bounded(-55, 595), gen->bounded(-55, 285));
    this->amount = 100;
    this->area = circle;
}

double grass::get_x() //геттер для координаты x
{
    return area->pos().x();
}

double grass::get_y() //геттер для координаты y
{
    return area->pos().y();
}

void grass::vanish() //уменьшение количества
{
    amount-=10;
    if(amount < 0)
        amount = 0;
}

void grass::set_area(QGraphicsEllipseItem *area) //сеттер для графического элемента
{
    this->area=area;
}

int grass::get_amount() //геттер для количества
{
    return amount;
}

QGraphicsEllipseItem* grass::get_area() //геттер для графического элемента
{
    return area;
}

grass::~grass() //деструктор
{

}
