#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

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

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    /*加抗锯齿*/
//    painter.setPen(QPen(Qt::red, 15));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    painter.setRenderHints(QPainter::Antialiasing);  // 抗锯齿操作
//    painter.translate(100, 0);  // 向右偏移100
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

    /*坐标系变换*/
//    painter.setPen(QPen(Qt::red, 10));
//    painter.drawLine(QPoint(10, 10), QPoint(100, 100));
//    painter.save();  // 保存当前坐标系状态

//    painter.translate(200, 0);
//    painter.rotate(90);  // 顺时针旋转90°
//    painter.setPen(QPen(Qt::blue, 10));
//    painter.drawLine(QPoint(10, 10), QPoint(100, 100));
//    painter.restore();  // 恢复为之前存的坐标系状态

    /*坐标缩放*/
//    painter.setPen(QPen(Qt::red, 2));
//    painter.setBrush(Qt::yellow);
//    painter.drawRect(50, 50, 50, 50);
//    painter.save();

//    painter.scale(0.5, 0.5);  // xy缩放
//    painter.setBrush(Qt::green);
//    painter.drawRect(50, 50, 50, 50);
//    painter.restore();

    /*坐标系的扭曲(shear)*/
    painter.setPen(QPen(Qt::blue));
    painter.setBrush(Qt::yellow);
    painter.drawRect(50, 50, 50, 50);
    painter.save();

    painter.shear(0.5, 0.5);
    painter.setBrush(Qt::gray);
    painter.drawRect(50, 50, 50, 50);
    painter.restore();
}
