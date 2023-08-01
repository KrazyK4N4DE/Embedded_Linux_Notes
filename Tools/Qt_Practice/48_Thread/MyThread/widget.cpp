#include "widget.h"
#include "ui_widget.h"
#include "mythread.h"

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
    thread.start();
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}

void Widget::on_pushButton_2_clicked()
{
    if(thread.isRunning())
    {
        thread.stop();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
    }

}

void Widget::on_pushButton_3_clicked()
{
    thread_2.start();
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(true);
}

void Widget::on_pushButton_4_clicked()
{
    if(thread_2.isRunning())
    {
        thread_2.stop();
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(false);
    }
}
