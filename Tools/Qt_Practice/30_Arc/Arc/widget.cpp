#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QtMath>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(1600, 900);
    this->setStyleSheet("background-color: black");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPen pen;
    painter.setRenderHints(QPainter::Antialiasing);

    pen.setColor(Qt::green);
    painter.setPen(pen);

    painter.drawArc(100, 100, 1400, 1400, 0 * 16, 180 * 16);  // * 16相当于单位，是由于换算的原因
    painter.drawArc(240, 240, 1120, 1120, 0 * 16, 180 * 16);
    painter.drawArc(380, 380, 840, 840, 0 * 16, 180 * 16);
    painter.drawArc(520, 520, 560, 560, 0 * 16, 180 * 16);
    painter.drawArc(660, 660, 280, 280, 0 * 16, 180 * 16);
}
