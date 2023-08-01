/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSb;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionClose;
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_B;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(565, 325);
        actionSb = new QAction(MainWindow);
        actionSb->setObjectName(QStringLiteral("actionSb"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, -20, 201, 241));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 0, 101, 51));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 0, 101, 51));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 60, 101, 51));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(330, 60, 101, 51));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(210, 120, 101, 51));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(330, 120, 101, 51));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(210, 180, 101, 51));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(330, 180, 101, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 565, 17));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_B = new QMenu(menuBar);
        menu_B->setObjectName(QStringLiteral("menu_B"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_B->menuAction());
        menu_F->addAction(actionNew);
        menu_F->addAction(actionOpen);
        menu_F->addSeparator();
        menu_F->addAction(actionClose);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionClose);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSb->setText(QApplication::translate("MainWindow", "New", 0));
        actionNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        actionClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\226\207\344\273\266", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\345\257\271\350\257\235\346\241\206", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\257\271\350\257\235\346\241\206", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223\345\257\271\350\257\235\346\241\206", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "\350\277\233\345\272\246\345\257\271\350\257\235\346\241\206", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "\351\224\231\350\257\257\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "\345\220\221\345\257\274\345\257\271\350\257\235\346\241\206", 0));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", 0));
        menu_B->setTitle(QApplication::translate("MainWindow", "\346\236\204\345\273\272(&B)", 0));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "\346\265\256\345\212\250\347\252\227\345\217\243", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
