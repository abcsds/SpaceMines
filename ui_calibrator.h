/********************************************************************************
** Form generated from reading UI file 'calibrator.ui'
**
** Created: Wed Apr 24 15:58:39 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATOR_H
#define UI_CALIBRATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calibrator
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *Position;
    QLabel *positionLabel;
    QLabel *label;
    QSlider *colorSlider;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *SLabel;
    QSlider *STopSlider;
    QSlider *SBottomSlider;
    QVBoxLayout *verticalLayout_2;
    QLabel *VLabel;
    QSlider *VTopSilder;
    QSlider *VBottomSlider;
    QPushButton *capturarButton;
    QPushButton *camaraButton;
    QPushButton *pushButton;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *Calibrator)
    {
        if (Calibrator->objectName().isEmpty())
            Calibrator->setObjectName(QString::fromUtf8("Calibrator"));
        Calibrator->resize(518, 353);
        centralWidget = new QWidget(Calibrator);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        Position = new QLabel(centralWidget);
        Position->setObjectName(QString::fromUtf8("Position"));

        verticalLayout_3->addWidget(Position);

        positionLabel = new QLabel(centralWidget);
        positionLabel->setObjectName(QString::fromUtf8("positionLabel"));

        verticalLayout_3->addWidget(positionLabel);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        colorSlider = new QSlider(centralWidget);
        colorSlider->setObjectName(QString::fromUtf8("colorSlider"));
        colorSlider->setMinimum(5);
        colorSlider->setMaximum(175);
        colorSlider->setSingleStep(1);
        colorSlider->setValue(45);
        colorSlider->setSliderPosition(45);
        colorSlider->setOrientation(Qt::Horizontal);
        colorSlider->setTickPosition(QSlider::TicksAbove);
        colorSlider->setTickInterval(10);

        verticalLayout_3->addWidget(colorSlider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        SLabel = new QLabel(centralWidget);
        SLabel->setObjectName(QString::fromUtf8("SLabel"));

        verticalLayout->addWidget(SLabel);

        STopSlider = new QSlider(centralWidget);
        STopSlider->setObjectName(QString::fromUtf8("STopSlider"));
        STopSlider->setMaximum(255);
        STopSlider->setValue(255);
        STopSlider->setOrientation(Qt::Horizontal);
        STopSlider->setTickPosition(QSlider::TicksBelow);

        verticalLayout->addWidget(STopSlider);

        SBottomSlider = new QSlider(centralWidget);
        SBottomSlider->setObjectName(QString::fromUtf8("SBottomSlider"));
        SBottomSlider->setMaximum(255);
        SBottomSlider->setSingleStep(1);
        SBottomSlider->setValue(120);
        SBottomSlider->setOrientation(Qt::Horizontal);
        SBottomSlider->setTickPosition(QSlider::TicksBelow);

        verticalLayout->addWidget(SBottomSlider);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        VLabel = new QLabel(centralWidget);
        VLabel->setObjectName(QString::fromUtf8("VLabel"));

        verticalLayout_2->addWidget(VLabel);

        VTopSilder = new QSlider(centralWidget);
        VTopSilder->setObjectName(QString::fromUtf8("VTopSilder"));
        VTopSilder->setMaximum(255);
        VTopSilder->setValue(255);
        VTopSilder->setOrientation(Qt::Horizontal);
        VTopSilder->setTickPosition(QSlider::TicksBelow);

        verticalLayout_2->addWidget(VTopSilder);

        VBottomSlider = new QSlider(centralWidget);
        VBottomSlider->setObjectName(QString::fromUtf8("VBottomSlider"));
        VBottomSlider->setMaximum(255);
        VBottomSlider->setValue(50);
        VBottomSlider->setOrientation(Qt::Horizontal);
        VBottomSlider->setTickPosition(QSlider::TicksBelow);

        verticalLayout_2->addWidget(VBottomSlider);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        capturarButton = new QPushButton(centralWidget);
        capturarButton->setObjectName(QString::fromUtf8("capturarButton"));

        verticalLayout_3->addWidget(capturarButton);

        camaraButton = new QPushButton(centralWidget);
        camaraButton->setObjectName(QString::fromUtf8("camaraButton"));

        verticalLayout_3->addWidget(camaraButton);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        Calibrator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Calibrator);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 518, 22));
        Calibrator->setMenuBar(menuBar);

        retranslateUi(Calibrator);
        QObject::connect(pushButton, SIGNAL(clicked()), Calibrator, SLOT(close()));

        QMetaObject::connectSlotsByName(Calibrator);
    } // setupUi

    void retranslateUi(QMainWindow *Calibrator)
    {
        Calibrator->setWindowTitle(QApplication::translate("Calibrator", "Calibrator", 0, QApplication::UnicodeUTF8));
        Position->setText(QApplication::translate("Calibrator", "Position:", 0, QApplication::UnicodeUTF8));
        positionLabel->setText(QString());
        label->setText(QApplication::translate("Calibrator", "Hue", 0, QApplication::UnicodeUTF8));
        SLabel->setText(QApplication::translate("Calibrator", "Saturation", 0, QApplication::UnicodeUTF8));
        VLabel->setText(QApplication::translate("Calibrator", "Value", 0, QApplication::UnicodeUTF8));
        capturarButton->setText(QApplication::translate("Calibrator", "Capturar", 0, QApplication::UnicodeUTF8));
        camaraButton->setText(QApplication::translate("Calibrator", "Mostrar", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Calibrator", "Cerrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Calibrator: public Ui_Calibrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATOR_H
