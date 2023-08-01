#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer* timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, [&](){update();});
}

Widget::~Widget()
{
    delete ui;
}

/*
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QFont font("华文琥珀", 20, QFont::Bold, true);  // 设置字体
    font.setUnderline(true);

    painter.setFont(font);
    painter.setPen(Qt::blue);
    painter.drawText(50, 50, "你好");
}
*/

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPainterPath path;

    /*绘制路径*/
    path.moveTo(50, 250);
    path.lineTo(50, 200);
    path.lineTo(100, 100);
    path.addEllipse(QPoint(100, 100), 30, 30);
    painter.setPen(Qt::red);
    painter.drawPath(path);

    path.translate(200, 0);
    painter.setPen(Qt::blue);
    painter.drawPath(path);
}
