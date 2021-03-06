#include "predator.h"
#include "prey.h"
#include "zebra.h"
#include "buffalo.h"
#include "mainwindow.h"

#include <QRandomGenerator>
#include <QPainter>
#include <QTimer>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

predator::predator(QObject *parent) : QObject(parent) //конструктор
{
    QRandomGenerator *gen = QRandomGenerator::global();
    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem();
    circle->setRect(20.0, 20.0, 20.0, 20.0);;
    circle->setBrush(Qt::yellow);
    circle->setPos(gen->bounded(-15, 715), gen->bounded(-15, 365));
    this->hunger = gen->bounded(90, 100);
    this->stamina = gen->bounded(1, 100);
    this->animal = circle;
}

QGraphicsEllipseItem* predator::get_animal() //геттер для графического элемента
{
    return animal;
}

double predator::get_x() //геттер для координаты x
{
    return animal->pos().x();
}

double predator::get_y() //геттер для координаты y
{
    return animal->pos().y();
}

int predator::get_hunger() //геттер для голода
{
    return hunger;
}

int predator::get_stamina() //геттер для выносливости
{
    return stamina;
}

double predator::check_distance(class prey *animal_single) //рассчет расстояния до жертвы
{
    double x_dist = 0;
    double y_dist = 0;
    x_dist = get_x() - animal_single->get_x();
    y_dist = get_y() - animal_single->get_y();
    return qSqrt(x_dist * x_dist + y_dist * y_dist);
}

void predator::hunt() //охота
{
    if(hunger<100)
        hunger+=5;
    else
        hunger=100;
    if(stamina>0)
        stamina-=15;
    else
        stamina=0;;
}

void predator::eat(class zebra *animal) //поедание зебры
{
    if(hunger>0)
        hunger-=10;
    else
        hunger=0;
    if(stamina<100)
        stamina+=5;
    else
        stamina=100;
    animal->set_status(0);
}

void predator::eat(class buffalo *animal) //поедание буйвола
{
    if(hunger>0)
        hunger-=15;
    else
        hunger=0;
    if(stamina<100)
        stamina+=10;
    else
        stamina=100;
    animal->set_status(0);
}

void predator::rest() //отдых
{
    if(hunger<100)
        hunger+=5;
    else
        hunger=100;
    if(stamina<100)
        stamina+=25;
    else
        stamina=100;
}

void predator::damage() //получение урона
{
    if(hunger<100)
        hunger+=5;
    else
        hunger=100;
    if(stamina>0)
        stamina-=15;
    else
        stamina=0;
}

void predator::damage(int horns) //получение урона от рогов
{
    if(horns >= 75)
    {
        if(hunger<100)
            hunger+=20;
        else
            hunger=100;
        if(stamina>0)
            stamina-=30;
        else
            stamina=0;
    }
    if(horns < 75 && horns >= 50)
    {
        if(hunger<100)
            hunger+=15;
        else
            hunger=100;
        if(stamina>0)
            stamina-=25;
        else
            stamina=0;
    }
    if(horns < 50 && horns >= 25)
    {
        if(hunger<100)
            hunger+=10;
        else
            hunger=100;
        if(stamina>0)
            stamina-=20;
        else
            stamina=0;
    }
    if(horns < 25 && horns >= 0)
    {
        if(hunger<100)
            hunger+=5;
        else
            hunger=100;
        if(stamina>0)
            stamina-=15;
        else
            stamina=0;
    }
}

predator::~predator() //деструктор
{

}
