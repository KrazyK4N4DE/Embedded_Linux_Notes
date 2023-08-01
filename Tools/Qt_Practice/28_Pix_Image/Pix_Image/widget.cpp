#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*QPixmap*/
//    QPixmap pix(400, 300);  // 不用到当前窗体了，故不用写在Event里
//    pix.fill(Qt::white);
//    QPainter painter(&pix);  // QPixmap继承了QPaintDevice
//    painter.setPen(Qt::red);
//    painter.drawEllipse(QPoint(100, 100), 50, 50);
//    pix.save("D:/myPix.jpg");

    /*QImage*/
//    QImage img(400, 300, QImage::Format_RGB32);
//    img.fill(Qt::white);
//    QPainter painter(&img);
//    painter.setPen(Qt::red);
//    painter.drawEllipse(QPoint(100, 100), 50, 50);
//    img.save("D:/myImg.jpg");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QImage img;
    img.load(":/Images/Images/optimus_prime.jpeg");
    for(int i = 50; i < 100; ++i)
    {
        for(int j = 50; j < 100; ++j)
        {
            QRgb rgb = qRgb(255, 0, 0);
            img.setPixel(i, j, rgb);
        }
    }
    painter.drawImage(0, 0, img);
}
