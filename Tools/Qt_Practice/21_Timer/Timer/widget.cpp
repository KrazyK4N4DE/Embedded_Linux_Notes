#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*定时器：方法1*/
    QTimer* timer = new QTimer(this);
    timer->start(1000);  // 单位：ms
    connect(timer, &QTimer::timeout, [&](){static int num = 1; ui->label->setText(QString::number(num++));});

    /*定时器：方法2*/
    time_id1 = startTimer(500);
    time_id2 = startTimer(2000);  // 利用返回值辨识不同的定时器

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == time_id1)
    {
        static int num1 = 1;
        ui->label_2->setText(QString::number(num1++));
    }
    if(event->timerId() == time_id2)
    {
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }
}
