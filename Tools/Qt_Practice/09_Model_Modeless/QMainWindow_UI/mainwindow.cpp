#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDialog* dialog = new QDialog(this);
    dialog->resize(200, 100);
//    dialog->show();  // 非模态
//    dialog->exec();  // 模态：方式1。涉及阻塞？
    dialog->setModal(true);  // 模态：方式2
    dialog->show();

    dialog->setAttribute(Qt::WA_DeleteOnClose);  // 相当于对话框的析构函数，释放空间，因为对话框只有在MainWindow关闭后才会释放

    // 添加Qt资源文件使用格式 ": + 前缀 + 文件名"
    ui->actionNew->setIcon(QIcon(":/Images/star.ico"));
    ui->actionOpen->setIcon(QIcon(":/Images/python.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
