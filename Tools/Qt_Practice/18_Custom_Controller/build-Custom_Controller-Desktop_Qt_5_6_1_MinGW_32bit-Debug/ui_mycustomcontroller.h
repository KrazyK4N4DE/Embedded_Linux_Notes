/********************************************************************************
** Form generated from reading UI file 'mycustomcontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCUSTOMCONTROLLER_H
#define UI_MYCUSTOMCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyCustomController
{
public:
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *MyCustomController)
    {
        if (MyCustomController->objectName().isEmpty())
            MyCustomController->setObjectName(QStringLiteral("MyCustomController"));
        MyCustomController->resize(281, 50);
        spinBox = new QSpinBox(MyCustomController);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(10, 10, 61, 31));
        horizontalSlider = new QSlider(MyCustomController);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(100, 10, 171, 31));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(MyCustomController);

        QMetaObject::connectSlotsByName(MyCustomController);
    } // setupUi

    void retranslateUi(QWidget *MyCustomController)
    {
        MyCustomController->setWindowTitle(QApplication::translate("MyCustomController", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MyCustomController: public Ui_MyCustomController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCUSTOMCONTROLLER_H
