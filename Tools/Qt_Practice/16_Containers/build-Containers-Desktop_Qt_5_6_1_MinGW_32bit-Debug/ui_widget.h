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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QWidget *page_6;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_3;
    QWidget *page_4;
    QWidget *page_2;
    QWidget *page_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QPushButton *ScrollArea;
    QPushButton *ToolBox;
    QPushButton *TabWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(443, 299);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 30, 261, 241));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        scrollArea = new QScrollArea(page_5);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(20, 30, 171, 201));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 169, 199));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        toolBox = new QToolBox(page_6);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(40, 40, 171, 191));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 171, 107));
        toolBox->addItem(page, QString::fromUtf8("\344\272\262\344\272\272"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        toolBox->addItem(page_3, QString::fromUtf8("\345\220\214\345\255\246"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        toolBox->addItem(page_4, QString::fromUtf8("\347\220\203\345\217\213"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 171, 107));
        toolBox->addItem(page_2, QString::fromUtf8("\345\220\214\344\272\213"));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        tabWidget = new QTabWidget(page_7);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 30, 231, 201));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        stackedWidget->addWidget(page_7);
        ScrollArea = new QPushButton(Widget);
        ScrollArea->setObjectName(QStringLiteral("ScrollArea"));
        ScrollArea->setGeometry(QRect(290, 90, 131, 31));
        ToolBox = new QPushButton(Widget);
        ToolBox->setObjectName(QStringLiteral("ToolBox"));
        ToolBox->setGeometry(QRect(290, 140, 131, 31));
        TabWidget = new QPushButton(Widget);
        TabWidget->setObjectName(QStringLiteral("TabWidget"));
        TabWidget->setGeometry(QRect(290, 190, 131, 31));

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);
        toolBox->setCurrentIndex(1);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_7->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_8->setText(QApplication::translate("Widget", "PushButton", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Widget", "\344\272\262\344\272\272", 0));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("Widget", "\345\220\214\345\255\246", 0));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("Widget", "\347\220\203\345\217\213", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("Widget", "\345\220\214\344\272\213", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "Device", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "Target", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "Output", 0));
        ScrollArea->setText(QApplication::translate("Widget", "ScrollArea", 0));
        ToolBox->setText(QApplication::translate("Widget", "ToolBox", 0));
        TabWidget->setText(QApplication::translate("Widget", "TabWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
