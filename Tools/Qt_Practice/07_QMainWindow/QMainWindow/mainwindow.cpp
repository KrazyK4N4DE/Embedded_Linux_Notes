#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(400, 300);

    /*菜单栏*/
    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);
    // 添加菜单栏选项
    QMenu* filename = menubar->addMenu("File(&F)");
    QMenu* editname = menubar->addMenu("Edit(&E)");
    QMenu* buildname = menubar->addMenu("Build(&B)");
    // 子选项
    filename->addAction("New File(&N)");
    filename->addAction("Open File(&O)");
    filename->addSeparator();  // 分隔线
    filename->addAction("Close File(&C)");
    editname->addAction("Recover(&U)");
    buildname->addAction("Build All(&R)");

    /*工具栏*/
    QToolBar* toolbar = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, toolbar);
    // 添加工具栏选项
    toolbar->addAction("New");
    toolbar->addAction("Open");
    toolbar->addSeparator();
    toolbar->addAction("Close");

    /*状态栏*/
    QStatusBar* stsbar = new QStatusBar(this);
    setStatusBar(stsbar);
    // 给状态栏添加东西
    QLabel* label = new QLabel(this);
    label->setText("StatusBar");
    stsbar->addWidget(label);

    /*中心组件：文本编辑器*/
    QTextEdit* edit = new QTextEdit(this);
    setCentralWidget(edit);

    /*浮动窗口*/
    QDockWidget* dockwidget = new QDockWidget("小窗口", this);
    addDockWidget(Qt::RightDockWidgetArea, dockwidget);  // 位置是相对与中心widget放哪的
}

MainWindow::~MainWindow()
{

}
