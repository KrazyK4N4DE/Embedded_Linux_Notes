#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    myprocess.start("C:/Qt/Qt5.12.8/5.12.8/mingw73_64/bin/assistant.exe");  // 通过一个进程启动另外一个进程
    myprocess.waitForFinished();  // 将父进程变为阻塞状态
}

void Widget::on_pushButton_2_clicked()
{
    qDebug() << "Hello World";  // 启动另外一个进程后，父进程可以接着工作
}
