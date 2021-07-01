#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "predator.h"
#include "prey.h"
#include "zebra.h"
#include "buffalo.h"

#include <QtMath>
#include <QGraphicsEllipseItem>
#include <QRandomGenerator>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPointF>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QKeyEvent>

MainWindow::MainWindow(int lions_num, int zebras_num, int buffalos_num, int grass_num, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);

    QGraphicsScene *scene_new = new QGraphicsScene;
    this->scene = scene_new;
    scene->addPixmap(QPixmap("C:/qt_projects/PracticeWork/field.png"));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(0,0,760,410);

    /*QGraphicsEllipseItem *circle = new QGraphicsEllipseItem();
    circle->setRect(20.0, 20.0, 20.0, 20.0);
    circle->setBrush(Qt::blue);
    circle->setPos(715, 250);
    QGraphicsEllipseItem *oval = new QGraphicsEllipseItem();
    oval->setRect(60.0, 60.0, 100.0, 60.0);
    oval->setBrush(Qt::green);
    oval->setPos(595, 150);
    scene->addItem(oval);
    scene->addItem(circle);*/

    this->lions_num = lions_count = lions_num;
    this->zebras_num = zebras_count = zebras_num;
    this->buffalos_num = buffalos_count = buffalos_num;
    this->grass_num = field_count = grass_num;

    for(int i = 0; i < grass_num; i ++)
    {
        this->field[i] = new grass();
        scene->addItem(field[i]->get_area());
    }
    for(int i = 0; i < zebras_num; i ++)
    {
        this->zebras[i] = new zebra();
        scene->addItem(zebras[i]->get_animal());
    }
    for(int i = 0; i < buffalos_num; i ++)
    {
        this->buffalos[i] = new buffalo();
        scene->addItem(buffalos[i]->get_animal());
    }
    for(int i = 0; i < lions_num; i ++)
    {
        this->lions[i] = new predator();
        scene->addItem(lions[i]->get_animal());
    }
    ui->graphicsView->show();

    ui->label_lions->setText("Lions:    YELLOW");
    ui->label_zebras->setText("Zebras:    WHITE");
    ui->label_buffalos->setText("Buffalos:    BLACK");
    ui->label_grass->setText("Grass:    GREEN");

    /*ui->label_lions->setText("Lions:    " + QString::number(lions_count));
    ui->label_zebras->setText("Zebras:  " + QString::number(zebras_count));
    ui->label_buffalos->setText("Buffalos:  " + QString::number(buffalos_count));
    ui->label_grass->setText("Grass:    " + QString::number(field_count));*/


    timer_main = new QTimer(this);
    connect(timer_main, &QTimer::timeout, this, QOverload<>::of(&MainWindow::move));
    timer_main->start(500);
}

void MainWindow::move()
{
    QRandomGenerator *gen = QRandomGenerator::global();
    QRandomGenerator *gen1 = QRandomGenerator::global();
    QRandomGenerator *gen2 = QRandomGenerator::global();
    QRandomGenerator *gen3 = QRandomGenerator::global();
    QPointF step;

    int direction = 0;
    int min_distance_lions = 0;
    int min_distance_zebras = 0;
    int min_distance_buffalos = 0;

    int flag_lions = 0;
    int flag_zebras = 0;
    int flag_buffalos = 0;

    int index_lions = 0;
    int index_zebras = 0;
    int index_buffalos = 0;

    //int zebras_count = zebras_num;
    //int buffalos_count = buffalos_num;
    //int field_count = grass_num;

    QPointF new_point;
    QPointF test_point;
    QGraphicsItemAnimation *animation;
    QTimeLine *timer;
    for(int i = 0; i < lions_num; i ++) //цикл обработки движения львов
    {
        step.setX(0);
        step.setY(0);
        if(lions[i]->get_stamina()<50)
        {
            lions[i]->get_animal()->setPos(lions[i]->get_animal()->pos());
            lions[i]->rest();
        }
        else
        {
            if(lions[i]->get_hunger()>50 && zebras_count!=0)
            {
                //step.setX(0);
                //step.setY(0);
                for(int j = 0; j < zebras_num; j ++)
                {
                    if(zebras[j]->get_status() && !flag_lions)
                    {
                        min_distance_lions = lions[i]->check_distance(zebras[j]);
                        step.setX(zebras[j]->get_x() - gen3->bounded(10, 15));
                        step.setY(zebras[j]->get_y() - gen3->bounded(10, 15));
                        index_lions = j;
                        flag_lions++;
                    }
                    if(zebras[j]->get_status() && flag_lions)
                    {
                        if(min_distance_lions > lions[i]->check_distance(zebras[j]))
                        {
                            min_distance_lions = lions[i]->check_distance(zebras[j]);
                            step.setX(zebras[j]->get_x() - gen3->bounded(10, 15));
                            step.setY(zebras[j]->get_y() - gen3->bounded(10, 15));
                            index_lions = j;
                        }
                    }
                }
                if(flag_lions)
                {
                    flag_lions = 0;
                    lions[i]->hunt();

                    timer = new QTimeLine(animation_time, this);
                    animation = new QGraphicsItemAnimation(timer);

                    connect(timer, SIGNAL(finished()), SLOT(update()));
                    animation->setItem(lions[i]->get_animal());
                    animation->setTimeLine(timer);

                    //new_point.setX(lions[i]->get_x() + step.x());
                    //new_point.setY(lions[i]->get_y() + step.y());

                    animation->setPosAt(1.0, step);
                    timer->start();

                    if(qFabs(qFabs(lions[i]->get_animal()->pos().x()) - qFabs(step.x())) <=2 && qFabs(qFabs(lions[i]->get_animal()->pos().y()) - qFabs(step.y())) <= 2)
                    {
                        if(zebras[index_lions]->get_courage()>50 && gen2->bounded(1,100) <= 20)
                        {
                            zebras[index_lions]->fight();
                            lions[i]->damage();
                        }
                        else
                        {
                            zebras[index_lions]->set_status(0);
                            scene->removeItem(zebras[index_lions]->get_animal());
                            //delete zebras[index_lions]->get_animal();
                            zebras[index_lions]->set_animal(nullptr);
                            lions[i]->eat(zebras[index_lions]);
                            zebras_count--;
                            //ui->label_zebras->setText("Zebras:  " + QString::number(zebras_count));
                            //update();
                        }
                    }
                }
            }

            if(lions[i]->get_hunger()>50 && zebras_count==0 && buffalos_count!=0)
            {
                //step.setX(0);
                //step.setY(0);
                for(int j = 0; j < buffalos_num; j ++)
                {
                    if(buffalos[j]->get_status() && !flag_lions)
                    {
                        min_distance_lions = lions[i]->check_distance(buffalos[j]);
                        step.setX(buffalos[j]->get_x() - gen3->bounded(10, 15));
                        step.setY(buffalos[j]->get_y() - gen3->bounded(10, 15));
                        index_lions = j;
                        flag_lions++;
                    }
                    if(buffalos[j]->get_status() && flag_lions)
                    {
                        if(min_distance_lions > lions[i]->check_distance(buffalos[j]))
                        {
                            min_distance_lions = lions[i]->check_distance(buffalos[j]);
                            step.setX(buffalos[j]->get_x() - gen3->bounded(10, 15));
                            step.setY(buffalos[j]->get_y() - gen3->bounded(10, 15));
                            index_lions = j;
                        }
                    }
                }
                if(flag_lions)
                {
                    flag_lions = 0;
                    lions[i]->hunt();

                    timer = new QTimeLine(animation_time, this);
                    animation = new QGraphicsItemAnimation(timer);

                    connect(timer, SIGNAL(finished()), SLOT(update()));
                    animation->setItem(lions[i]->get_animal());
                    animation->setTimeLine(timer);

                    //new_point.setX(lions[i]->get_x() + step.x());
                    //new_point.setY(lions[i]->get_y() + step.y());

                    animation->setPosAt(1.0, step);
                    timer->start();

                    if(qFabs(qFabs(lions[i]->get_animal()->pos().x()) - qFabs(step.x())) <=2 && qFabs(qFabs(lions[i]->get_animal()->pos().y()) - qFabs(step.y())) <= 2)
                    {
                        if(buffalos[index_lions]->get_courage()>50 && gen2->bounded(1,100) <= 20)
                        {
                            buffalos[index_lions]->fight();
                            lions[i]->damage(buffalos[index_lions]->get_horns_durability());
                        }
                        else
                        {
                            buffalos[index_lions]->set_status(0);
                            scene->removeItem(buffalos[index_lions]->get_animal());
                            //delete buffalos[index_lions]->get_animal();
                            buffalos[index_lions]->set_animal(nullptr);
                            lions[i]->eat(buffalos[index_lions]);
                            buffalos_count--;
                            //ui->label_buffalos->setText("Buffalos:  " + QString::number(buffalos_count));
                            //update();
                        }
                    }
                }
            }

            step.setX(0);
            step.setY(0);
            new_point.setX(0);
            new_point.setY(0);
            direction = gen->bounded(1, 4);
            switch(direction)
            {
                case 1:
                {
                    step.setX(gen1->bounded(10, 50) * (-1)); //left
                    if(lions[i]->get_x() + step.x() < -15)
                        step.setX(step.x() * (-1));
                    break;
                }
                case 2:
                {
                    step.setX(gen1->bounded(10, 50)); //right
                    if(lions[i]->get_x() + step.x() > 715)
                        step.setX(step.x() * (-1));
                    break;
                }
                case 3:
                {
                    step.setY(gen1->bounded(10, 50) * (-1)); //up
                    if(lions[i]->get_y() + step.y() < -15)
                        step.setY(step.y() * (-1));
                    break;
                }
                case 4:
                {
                    step.setY(gen1->bounded(10, 50)); //down
                    if(lions[i]->get_y() + step.y() > 365)
                        step.setY(step.y() * (-1));
                    break;
                }
            }
            timer = new QTimeLine(animation_time, this);
            animation = new QGraphicsItemAnimation(timer);

            connect(timer, SIGNAL(finished()), SLOT(update()));
            animation->setItem(lions[i]->get_animal());
            animation->setTimeLine(timer);

            test_point = lions[i]->get_animal()->pos();
            new_point = lions[i]->get_animal()->pos() + step;

            //new_point.setX(lions[i]->get_x() + step.x());
            //new_point.setY(lions[i]->get_y() + step.y());

            animation->setPosAt(1.0, new_point);
            timer->start();
        }
    }

    for(int i = 0; i < zebras_num; i ++) //цикл обработки движения зебр
    {
        step.setX(0);
        step.setY(0);
        direction = gen->bounded(1, 4);
        if(zebras[i]->get_status()!=0)
        {
            if(zebras[i]->get_stamina()<50 && field_count != 0)
            {
                for(int j = 0; j < grass_num; j ++)
                {
                    if(field[j]->get_amount() && !flag_zebras)
                    {
                        min_distance_zebras = zebras[i]->check_distance(field[j]);
                        step.setX(field[j]->get_x() + gen3->bounded(60, 130));
                        step.setY(field[j]->get_y() + gen3->bounded(50, 80));
                        index_zebras = j;
                        flag_zebras++;
                    }
                    if(field[j]->get_amount() && flag_zebras)
                    {
                        if(min_distance_zebras > zebras[i]->check_distance(field[j]))
                        {
                            min_distance_zebras = zebras[i]->check_distance(field[j]);
                            step.setX(field[j]->get_x() + gen3->bounded(60, 130));
                            step.setY(field[j]->get_y() + gen3->bounded(50, 80));
                            index_zebras = j;
                        }
                    }
                }
                if(flag_zebras)
                {
                    flag_zebras = 0;

                    timer = new QTimeLine(animation_time, this);
                    animation = new QGraphicsItemAnimation(timer);

                    connect(timer, SIGNAL(finished()), SLOT(update()));
                    animation->setItem(zebras[i]->get_animal());
                    animation->setTimeLine(timer);

                    //new_point.setX(lions[i]->get_x() + step.x());
                    //new_point.setY(lions[i]->get_y() + step.y());

                    animation->setPosAt(1.0, step);
                    timer->start();

                    if(qFabs(qFabs(zebras[i]->get_animal()->pos().x()) - qFabs(step.x())) <=25 && qFabs(qFabs(zebras[i]->get_animal()->pos().y()) - qFabs(step.y())) <= 25)
                    {
                        zebras[i]->eat(field[index_zebras]);

                        if(field[index_zebras]->get_amount() == 0)
                        {
                            scene->removeItem(field[index_zebras]->get_area());
                            //delete field[index_zebras]->get_area();
                            field[index_zebras]->set_area(nullptr);
                            field_count--;
                            //ui->label_grass->setText("Grass:    " + QString::number(field_count));
                            //update();
                        }
                    }
                }
            }
            //else
            //{
               step.setX(0);
               step.setY(0);
               new_point.setX(0);
               new_point.setY(0);
               direction = gen->bounded(1, 4);
               switch(direction)
               {
                   case 1:
                   {
                       step.setX(gen1->bounded(10, 40) * (-1)); //left
                       if(zebras[i]->get_x() + step.x() < -15)
                           step.setX(step.x() * (-1));
                       break;
                   }
                   case 2:
                   {
                       step.setX(gen1->bounded(10, 40)); //right
                       if(zebras[i]->get_x() + step.x() > 715)
                           step.setX(step.x() * (-1));
                       break;
                   }
                   case 3:
                   {
                       step.setY(gen1->bounded(10, 40) * (-1)); //up
                       if(zebras[i]->get_y() + step.y() < -15)
                           step.setY(step.y() * (-1));
                       break;
                   }
                   case 4:
                   {
                       step.setY(gen1->bounded(10, 40)); //down
                       if(zebras[i]->get_y() + step.y() > 365)
                           step.setY(step.y() * (-1));
                       break;
                   }
               }
               timer = new QTimeLine(animation_time, this);
               animation = new QGraphicsItemAnimation(timer);

               connect(timer, SIGNAL(finished()), SLOT(update()));
               animation->setItem(zebras[i]->get_animal());
               animation->setTimeLine(timer);

               //new_point.setX(zebras[i]->get_x() + step.x());
               //new_point.setY(zebras[i]->get_y() + step.y());

               test_point = zebras[i]->get_animal()->pos();
               new_point = zebras[i]->get_animal()->pos() + step;

               animation->setPosAt(1.0, new_point);
               timer->start();
            //}
        }
    }

    for(int i = 0; i < buffalos_num; i ++) //цикл обработки движения буйволов
    {
        step.setX(0);
        step.setY(0);
        new_point.setX(0);
        new_point.setY(0);
        direction = gen->bounded(1, 4);
        if(buffalos[i]->get_status()!=0)
        {
            if(buffalos[i]->get_stamina()<50 && field_count != 0)
            {
                for(int j = 0; j < grass_num; j ++)
                {
                    if(field[j]->get_amount() && !flag_buffalos)
                    {
                        min_distance_buffalos = buffalos[i]->check_distance(field[j]);
                        step.setX(field[j]->get_x() + gen3->bounded(60, 130));
                        step.setY(field[j]->get_y() + gen3->bounded(50, 80));
                        index_buffalos = j;
                        flag_buffalos++;
                    }
                    if(field[j]->get_amount() && flag_buffalos)
                    {
                        if(min_distance_buffalos > buffalos[i]->check_distance(field[j]))
                        {
                            min_distance_buffalos = buffalos[i]->check_distance(field[j]);
                            step.setX(field[j]->get_x() + gen3->bounded(60, 130));
                            step.setY(field[j]->get_y() + gen3->bounded(50, 80));
                            index_buffalos = j;
                        }
                    }
                }
                if(flag_buffalos)
                {
                    flag_buffalos = 0;

                    timer = new QTimeLine(animation_time, this);
                    animation = new QGraphicsItemAnimation(timer);

                    connect(timer, SIGNAL(finished()), SLOT(update()));
                    animation->setItem(buffalos[i]->get_animal());
                    animation->setTimeLine(timer);

                    //new_point.setX(lions[i]->get_x() + step.x());
                    //new_point.setY(lions[i]->get_y() + step.y());

                    animation->setPosAt(1.0, step);
                    timer->start();

                    if(qFabs(qFabs(buffalos[i]->get_animal()->pos().x()) - qFabs(step.x())) <=25 && qFabs(qFabs(buffalos[i]->get_animal()->pos().y()) - qFabs(step.y())) <= 25)
                    {
                        buffalos[i]->eat(field[index_buffalos]);

                        if(field[index_buffalos]->get_amount() == 0)
                        {
                            scene->removeItem(field[index_buffalos]->get_area());
                            //delete field[index_buffalos]->get_area();
                            field[index_buffalos]->set_area(nullptr);
                            field_count--;
                            //ui->label_grass->setText("Grass:    " + QString::number(field_count));
                            //update();
                        }
                    }
                }
            }
            //else
            //{
               step.setX(0);
               step.setY(0);
               direction = gen->bounded(1, 4);
               switch(direction)
               {
                   case 1:
                   {
                       step.setX(gen1->bounded(10, 40) * (-1)); //left
                       if(buffalos[i]->get_x() + step.x() < -15)
                           step.setX(step.x() * (-1));
                       break;
                   }
                   case 2:
                   {
                       step.setX(gen1->bounded(10, 40)); //right
                       if(buffalos[i]->get_x() + step.x() > 715)
                           step.setX(step.x() * (-1));
                       break;
                   }
                   case 3:
                   {
                       step.setY(gen1->bounded(10, 40) * (-1)); //up
                       if(buffalos[i]->get_y() + step.y() < -15)
                           step.setY(step.y() * (-1));
                       break;
                   }
                   case 4:
                   {
                       step.setY(gen1->bounded(10, 40)); //down
                       if(buffalos[i]->get_y() + step.y() > 365)
                           step.setY(step.y() * (-1));
                       break;
                   }
               }
               timer = new QTimeLine(animation_time, this);
               animation = new QGraphicsItemAnimation(timer);

               connect(timer, SIGNAL(finished()), SLOT(update()));
               animation->setItem(buffalos[i]->get_animal());
               animation->setTimeLine(timer);

               //new_point.setX(zebras[i]->get_x() + step.x());
               //new_point.setY(zebras[i]->get_y() + step.y());

               test_point = buffalos[i]->get_animal()->pos();
               new_point = buffalos[i]->get_animal()->pos() + step;

               animation->setPosAt(1.0, new_point);
               timer->start();
            //}
        }
    }
}

/*void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        QRandomGenerator *gen = QRandomGenerator::global();
        QRandomGenerator *gen1 = QRandomGenerator::global();
        QPointF step;
        step.setX(0);
        step.setY(0);
        int direction;
        QGraphicsItemAnimation *animation;
        QTimeLine *timer;
        for(int i = 0; i < lions_num; i ++)
        {
            direction = gen->bounded(1, 4);
            switch(direction)
            {
                case 1:
                {
                    step.setX(-gen1->bounded(10, 40)); //left
                    break;
                }
                case 2:
                {
                    step.setX(gen1->bounded(10, 40)); //right
                    break;
                }
                case 3:
                {
                    step.setY(-gen1->bounded(10, 40)); //up
                    break;
                }
                case 4:
                {
                    step.setY(gen1->bounded(10, 40)); //down
                    break;
                }
            }
            timer = new QTimeLine(animation_time, this);
            animation = new QGraphicsItemAnimation(timer);

            //connect(timer, SIGNAL(finished()), SLOT(animation_finish()));
            connect(timer, SIGNAL(finished()), SLOT(update()));
            animation->setItem(lions[i]->get_animal());
            animation->setTimeLine(timer);
            animation->setPosAt(1.0, lions[i]->calculate_position(step));
            timer->start();
            //lions[i]->set_position(step.x(), step.y());
        }
    }
}*/


void MainWindow::update_labels()
{
    ui->label_lions->setText("Lions:    " + QString::number(lions_count));
    ui->label_zebras->setText("Zebras:  " + QString::number(zebras_count));
    ui->label_buffalos->setText("Buffalos:  " + QString::number(buffalos_count));
    ui->label_grass->setText("Grass:    " + QString::number(field_count));
}

/*void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        update_labels();
    }
}*/

MainWindow::~MainWindow()
{
    /*delete[] lions[lions_num];
    delete[] zebras[zebras_num];
    delete[] buffalos[buffalos_num];
    delete[] field[grass_num];
    delete timer_main;
    delete scene;*/
    delete ui;
}






