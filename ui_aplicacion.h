/********************************************************************************
** Form generated from reading UI file 'aplicacion.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APLICACION_H
#define UI_APLICACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Aplicacion
{
public:
    QWidget *centralWidget;
    QLabel *labelLienzo;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *labelResultado;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelPegarResultadoInOrden;
    QVBoxLayout *verticalLayout_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Aplicacion)
    {
        if (Aplicacion->objectName().isEmpty())
            Aplicacion->setObjectName(QStringLiteral("Aplicacion"));
        Aplicacion->resize(610, 510);
        centralWidget = new QWidget(Aplicacion);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelLienzo = new QLabel(centralWidget);
        labelLienzo->setObjectName(QStringLiteral("labelLienzo"));
        labelLienzo->setGeometry(QRect(12, 12, 581, 321));
        labelLienzo->setAlignment(Qt::AlignCenter);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 350, 133, 96));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelResultado = new QLabel(widget);
        labelResultado->setObjectName(QStringLiteral("labelResultado"));

        verticalLayout->addWidget(labelResultado);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        verticalLayout_4->addLayout(verticalLayout_3);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(170, 350, 431, 96));
        verticalLayout_6 = new QVBoxLayout(widget1);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelPegarResultadoInOrden = new QLabel(widget1);
        labelPegarResultadoInOrden->setObjectName(QStringLiteral("labelPegarResultadoInOrden"));
        labelPegarResultadoInOrden->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelPegarResultadoInOrden);


        verticalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        verticalLayout_6->addLayout(verticalLayout_5);

        Aplicacion->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Aplicacion);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 610, 22));
        Aplicacion->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Aplicacion);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Aplicacion->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Aplicacion);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Aplicacion->setStatusBar(statusBar);

        retranslateUi(Aplicacion);

        QMetaObject::connectSlotsByName(Aplicacion);
    } // setupUi

    void retranslateUi(QMainWindow *Aplicacion)
    {
        Aplicacion->setWindowTitle(QApplication::translate("Aplicacion", "Aplicacion", 0));
        labelLienzo->setText(QApplication::translate("Aplicacion", "TextLabel", 0));
        labelResultado->setText(QApplication::translate("Aplicacion", "Resultado InOrden", 0));
        labelPegarResultadoInOrden->setText(QApplication::translate("Aplicacion", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Aplicacion: public Ui_Aplicacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APLICACION_H
