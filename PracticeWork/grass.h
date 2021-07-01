#ifndef GRASS_H
#define GRASS_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsEllipseItem>

class grass : public QObject
{
    Q_OBJECT
public:
    explicit grass(QObject *parent = nullptr);
private:
    int amount;
    QGraphicsEllipseItem *area;
public:
    double get_x();
    double get_y();
    void vanish();
    void set_area(QGraphicsEllipseItem *area);
    int get_amount();
    QGraphicsEllipseItem* get_area();
    ~grass();
signals:

};

#endif // GRASS_H
