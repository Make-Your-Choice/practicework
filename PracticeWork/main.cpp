#include "mainwindow.h"
#include "predator.h"
#include "prey.h"
#include "zebra.h"
#include "buffalo.h"
#include "grass.h"

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QApplication>
#include <QRandomGenerator>
#include <QTimer>
#include <QThread>

#define lions_max 10
#define zebras_max 10
#define buffalos_max 10
#define grass_max 10

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w(lions_max, zebras_max, buffalos_max, grass_max);

    //QTimer *timer_main = new QTimer();
    //QObject::connect(timer_main, &QTimer::timeout, &w, QOverload<>::of(&MainWindow::move));
    //timer_main->start(500);

    w.show();
    return a.exec();
}
