#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setText("I love U");
    /*图片*/
    ui->label_2->setPixmap(QPixmap(":/Images/Images/1.jpeg"));
    ui->label_2->setScaledContents(true);
    /*Label添加动图*/
    QMovie* mv = new QMovie(":/Images/Images/2.gif");
    ui->label_3->setMovie(mv);
    ui->label_3->setScaledContents(true);
    mv->start();
}

Widget::~Widget()
{
    delete ui;
}
