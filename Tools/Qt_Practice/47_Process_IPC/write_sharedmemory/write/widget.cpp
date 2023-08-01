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
    if(sharedmemory.isAttached()) sharedmemory.detach();  // 如果之前绑定有，解绑并创建新的
    if(!sharedmemory.create(100, QSharedMemory::ReadWrite))  // 100字节
    {
        qDebug() << "Failed to create shared memory!";
        return;
    }

    /*共享资源要上锁，防止自己用的时候别人用*/
    sharedmemory.lock();
    QByteArray arr = ui->lineEdit->text().toLatin1();
    memcpy(sharedmemory.data(), arr.data(), (size_t)qMin(sharedmemory.size(), ui->lineEdit->text().size()));  // lineEdit打到共享内存中
    sharedmemory.unlock();  // 解锁
}
