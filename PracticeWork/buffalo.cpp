#include "buffalo.h"
#include "predator.h"

#include <QRandomGenerator>

buffalo::buffalo(QObject *parent) : prey(parent)
{
    QRandomGenerator *gen = QRandomGenerator::global();
    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem();
    circle->setRect(20.0, 20.0, 20.0, 20.0);
    //circle->setBrush(Qt::red);
    circle->setBrush(Qt::black);
    circle->setPos(gen->bounded(-15, 715), gen->bounded(-15, 365));
    this->courage = gen->bounded(51, 100);
    this->stamina = gen->bounded(1, 100);
    this->horns_durability = gen->bounded(1, 100);
    this->status = 1;
    this->animal = circle;
}

int buffalo::get_horns_durability()
{
    return horns_durability;
}

void buffalo::fight()
{
    stamina-=10;
    horns_durability-=15;
}

buffalo::~buffalo()
{

}
