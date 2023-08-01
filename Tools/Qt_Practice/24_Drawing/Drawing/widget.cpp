#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(800, 600);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    /*构建画笔*/
    QPen pen(QColor(255, 0, 0));
    pen.setWidth(3);
    pen.setStyle(Qt::DashDotDotLine);
    painter.setPen(pen);

    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
    painter.drawEllipse(QPoint(100, 100), 30, 30);  // 画椭圆
    painter.drawEllipse(QPoint(100, 100), 50, 80);
    painter.drawRect(200, 100, 40, 40);
    painter.drawText(100, 200, "I love U");

    /*构建画刷*/
    QBrush brush(Qt::green, Qt::Dense1Pattern);
    painter.setBrush(brush);

    painter.drawRect(200, 200, 50, 80);

    /*渐变色*/
    QConicalGradient conicalGradient(QPointF(300, 100), 0);
    conicalGradient.setColorAt(0.2, Qt::cyan);  // 用0~1表示0~360°，这里表示到72°
    conicalGradient.setColorAt(0.4, Qt::black);
    conicalGradient.setColorAt(0.7, Qt::red);
    conicalGradient.setColorAt(11, Qt::yellow);
    painter.setBrush(conicalGradient);
    painter.drawEllipse(QPointF(300, 100), 50, 50);
}
