/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QToolButton *toolButton;
    QGroupBox *groupBox;
    QRadioButton *rB_grade1;
    QRadioButton *rB_grade2;
    QRadioButton *rB_grade3;
    QGroupBox *groupBox_2;
    QRadioButton *rB_score1;
    QRadioButton *rB_score2;
    QRadioButton *rB_score3;
    QRadioButton *rB_score4;
    QRadioButton *rB_score5;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_7;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(612, 413);
        toolButton = new QToolButton(Widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(10, 10, 101, 51));
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 80, 131, 161));
        rB_grade1 = new QRadioButton(groupBox);
        rB_grade1->setObjectName(QStringLiteral("rB_grade1"));
        rB_grade1->setGeometry(QRect(20, 30, 101, 21));
        rB_grade2 = new QRadioButton(groupBox);
        rB_grade2->setObjectName(QStringLiteral("rB_grade2"));
        rB_grade2->setGeometry(QRect(20, 70, 101, 21));
        rB_grade3 = new QRadioButton(groupBox);
        rB_grade3->setObjectName(QStringLiteral("rB_grade3"));
        rB_grade3->setGeometry(QRect(20, 110, 101, 21));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(160, 80, 151, 191));
        rB_score1 = new QRadioButton(groupBox_2);
        rB_score1->setObjectName(QStringLiteral("rB_score1"));
        rB_score1->setGeometry(QRect(20, 30, 111, 21));
        rB_score2 = new QRadioButton(groupBox_2);
        rB_score2->setObjectName(QStringLiteral("rB_score2"));
        rB_score2->setGeometry(QRect(20, 60, 111, 21));
        rB_score3 = new QRadioButton(groupBox_2);
        rB_score3->setObjectName(QStringLiteral("rB_score3"));
        rB_score3->setGeometry(QRect(20, 90, 111, 21));
        rB_score4 = new QRadioButton(groupBox_2);
        rB_score4->setObjectName(QStringLiteral("rB_score4"));
        rB_score4->setGeometry(QRect(20, 120, 111, 21));
        rB_score5 = new QRadioButton(groupBox_2);
        rB_score5->setObjectName(QStringLiteral("rB_score5"));
        rB_score5->setGeometry(QRect(20, 150, 111, 21));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(330, 80, 141, 191));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 30, 101, 21));
        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 70, 101, 21));
        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(20, 110, 101, 21));
        checkBox_7 = new QCheckBox(groupBox_3);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));
        checkBox_7->setGeometry(QRect(20, 150, 101, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        toolButton->setText(QApplication::translate("Widget", "\345\260\217\346\202\237\347\251\272", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\345\271\264\347\272\247", 0));
        rB_grade1->setText(QApplication::translate("Widget", "\344\270\200\345\271\264\347\272\247", 0));
        rB_grade2->setText(QApplication::translate("Widget", "\344\272\214\345\271\264\347\272\247", 0));
        rB_grade3->setText(QApplication::translate("Widget", "\344\270\211\345\271\264\347\272\247", 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\345\210\206\346\225\260", 0));
        rB_score1->setText(QApplication::translate("Widget", "90 - 100", 0));
        rB_score2->setText(QApplication::translate("Widget", "80 - 89", 0));
        rB_score3->setText(QApplication::translate("Widget", "70 - 79", 0));
        rB_score4->setText(QApplication::translate("Widget", "60 - 69", 0));
        rB_score5->setText(QApplication::translate("Widget", "< 60", 0));
        groupBox_3->setTitle(QApplication::translate("Widget", "\350\200\201\345\270\210\344\274\230\347\202\271", 0));
        checkBox->setText(QApplication::translate("Widget", "\344\272\272\345\270\205", 0));
        checkBox_2->setText(QApplication::translate("Widget", "\346\200\235\350\267\257\346\270\205\346\231\260", 0));
        checkBox_3->setText(QApplication::translate("Widget", "\344\273\243\347\240\201\347\256\200\346\264\201", 0));
        checkBox_7->setText(QApplication::translate("Widget", "\345\217\243\351\275\277\346\270\205\346\231\260", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
