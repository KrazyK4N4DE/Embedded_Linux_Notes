#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mc1 = new MyClass1(this);
    mc2 = new MyClass2(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::close);
    connect(mc1, &MyClass1::MySignal, mc2, &MyClass2::MySlot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    emit mc1->MySignal(num++);  // emit：发送
}
