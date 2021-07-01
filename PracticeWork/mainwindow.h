#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsEllipseItem>
#include <QTimeLine>
#include "predator.h"
#include "prey.h"
#include "zebra.h"
#include "buffalo.h"
#include "grass.h"

#define nmax 50

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int lions_num, int zebras_num, int buffalos_num, int grass_num, QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void update_labels();
    void move();
//protected slots:
    //void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    const int animation_time = 500;
    QTimer *timer_main;

    predator *lions[nmax];
    int lions_num;
    int lions_count;
    zebra *zebras[nmax];
    int zebras_num;
    int zebras_count;
    buffalo *buffalos[nmax];
    int buffalos_num;
    int buffalos_count;
    grass *field[nmax];
    int grass_num;
    int field_count;
//signals:
    //void valueChanged();
//public slots:
    //void set_new_value_zebras();

};
#endif // MAINWINDOW_H


