#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 添加Qt资源文件使用格式 ": + 前缀 + 文件名"
    ui->actionNew->setIcon(QIcon(":/Images/star.ico"));
    ui->actionOpen->setIcon(QIcon(":/Images/python.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
