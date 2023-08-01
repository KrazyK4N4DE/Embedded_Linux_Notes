#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QDir myDir("D:/Warehouse");
    ui->listWidget->addItem(myDir.absolutePath());

    myDir.setNameFilters(QStringList("*.txt"));
    ui->listWidget->addItems(myDir.entryList());

    /*监视文件夹*/
    myDir.mkdir("mydir");
    connect(&myWatcher, &QFileSystemWatcher::directoryChanged, this, &Widget::showMessage);
    connect(&myWatcher, &QFileSystemWatcher::fileChanged, this, &Widget::showMessage);
    myWatcher.addPath("D:/Warehouse/mydir");
    myWatcher.addPath("D:/Warehouse/test.txt");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showMessage(const QString &path)
{
    if(path == "D:/Warehouse/mydir") ui->listWidget->addItem("D:/Warehouse/mydir  目录发生改变");
    else ui->listWidget->addItem("D:/Warehouse/test.txt  目录发生改变");
}
