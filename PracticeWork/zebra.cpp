#include "zebra.h"
#include "predator.h"

#include <QRandomGenerator>

zebra::zebra(QObject *parent) : prey(parent)
{
    QRandomGenerator *gen = QRandomGenerator::global();
    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem();
    circle->setRect(20.0, 20.0, 20.0, 20.0);
    circle->setBrush(Qt::white);
    circle->setPos(gen->bounded(-15, 715), gen->bounded(-15, 365));
    this->courage = gen->bounded(51, 100);
    this->stamina = gen->bounded(1, 100);
    this->status = 1;
    this->animal = circle;
}

void zebra::fight()
{
    stamina-=15;
}

zebra::~zebra()
{

}
