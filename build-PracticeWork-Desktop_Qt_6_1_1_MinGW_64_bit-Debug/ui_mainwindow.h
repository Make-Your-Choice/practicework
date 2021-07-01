/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_stats;
    QLabel *label_lions;
    QLabel *label_zebras;
    QLabel *label_buffalos;
    QLabel *label_grass;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 40, 760, 410));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setContextMenuPolicy(Qt::DefaultContextMenu);
        graphicsView->setAutoFillBackground(false);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        graphicsView->setForegroundBrush(brush1);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 470, 761, 31));
        QFont font;
        font.setPointSize(10);
        widget->setFont(font);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_stats = new QLabel(widget);
        label_stats->setObjectName(QString::fromUtf8("label_stats"));
        label_stats->setFont(font);
        label_stats->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(label_stats);

        label_lions = new QLabel(widget);
        label_lions->setObjectName(QString::fromUtf8("label_lions"));
        label_lions->setFont(font);
        label_lions->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(label_lions);

        label_zebras = new QLabel(widget);
        label_zebras->setObjectName(QString::fromUtf8("label_zebras"));
        label_zebras->setFont(font);
        label_zebras->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(label_zebras);

        label_buffalos = new QLabel(widget);
        label_buffalos->setObjectName(QString::fromUtf8("label_buffalos"));
        label_buffalos->setFont(font);
        label_buffalos->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(label_buffalos);

        label_grass = new QLabel(widget);
        label_grass->setObjectName(QString::fromUtf8("label_grass"));
        label_grass->setFont(font);

        horizontalLayout->addWidget(label_grass);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_stats->setText(QCoreApplication::translate("MainWindow", "Statistics:", nullptr));
        label_lions->setText(QCoreApplication::translate("MainWindow", "Lions:", nullptr));
        label_zebras->setText(QCoreApplication::translate("MainWindow", "Zebras:", nullptr));
        label_buffalos->setText(QCoreApplication::translate("MainWindow", "Buffalos:", nullptr));
        label_grass->setText(QCoreApplication::translate("MainWindow", "Grass:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
