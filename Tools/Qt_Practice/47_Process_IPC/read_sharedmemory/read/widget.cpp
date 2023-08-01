#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    sharedmemory.setKey("My_Shared_Memory");  // 键值

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(!sharedmemory.attach())
    {
        qDebug() << "Attach sharedmemory failed!";
        return;
    }

    sharedmemory.lock();
    char* arr = new char[sharedmemory.size()];
    memcpy(arr, sharedmemory.data(), (size_t)sharedmemory.size());
    ui->label->setText(QString(arr));
    sharedmemory.unlock();
    sharedmemory.detach();
}
