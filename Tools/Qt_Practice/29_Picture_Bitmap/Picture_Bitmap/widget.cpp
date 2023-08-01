#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>
#include <QBitmap>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*QPicture*/
//    QPicture pic;
//    QPainter painter;
//    painter.begin(&pic);
//    painter.setPen(Qt::red);
//    painter.drawEllipse(QPoint(100, 100), 50, 50);
//    painter.end();
//    pic.save("D:/pic.weiwei");  // 因为是二进制文件，所以后缀没太大关系

    /*QBitmap*/
    QBitmap bm(400, 300);
    QPainter painter(&bm);
    painter.setPen(Qt::red);
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    bm.save("D:/bm.jpg");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

//    QPicture pic;
//    pic.load("D:/pic.weiwei");
//    painter.drawPicture(0, 0, pic);

    QBitmap bm;
    bm.load("D:/optimus_prime.jpeg");
    painter.drawPixmap(0, 0, bm);
}
