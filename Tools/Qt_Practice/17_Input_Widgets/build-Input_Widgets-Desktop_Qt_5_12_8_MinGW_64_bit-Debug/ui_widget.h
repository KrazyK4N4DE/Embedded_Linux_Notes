/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QComboBox *comboBox;
    QFontComboBox *fontComboBox;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPlainTextEdit *plainTextEdit;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QDateTimeEdit *dateTimeEdit;
    QDial *dial;
    QScrollBar *horizontalScrollBar;
    QSlider *horizontalSlider;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(460, 430);
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 20, 111, 41));
        fontComboBox = new QFontComboBox(Widget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(150, 60, 241, 41));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 20, 111, 31));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 20, 91, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 150, 113, 20));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 200, 171, 121));
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(220, 200, 171, 121));
        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(150, 110, 71, 22));
        doubleSpinBox = new QDoubleSpinBox(Widget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(150, 140, 71, 22));
        timeEdit = new QTimeEdit(Widget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(230, 110, 118, 22));
        dateEdit = new QDateEdit(Widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(230, 140, 121, 22));
        dateTimeEdit = new QDateTimeEdit(Widget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(150, 170, 201, 22));
        dial = new QDial(Widget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(10, 330, 50, 64));
        horizontalScrollBar = new QScrollBar(Widget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(80, 330, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(80, 380, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        label->setText(QApplication::translate("Widget", "\351\200\211\346\213\251\347\232\204\345\255\227\344\275\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
