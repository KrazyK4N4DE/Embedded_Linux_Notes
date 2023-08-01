#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QtMath>
#include <QTimer>
#include <QDebug>

int flag;

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(1600, 900);
    this->setStyleSheet("background-color: black");

    QTimer* timer = new QTimer(this);
    timer->start(20);
    connect(timer, &QTimer::timeout, this, &Widget::timerTimeOut);
}

Widget::~Widget()
{
    delete ui;
}

/*更新扫描角度的函数*/
void Widget::timerTimeOut(void)
{
    if(flag == 0)
    {
        ++angle;
        if(angle == 180) flag = 1;
    }
    else
    {
        --angle;
        if(angle == 0) flag = 0;
    }
    update();
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPen pen;
    painter.setRenderHints(QPainter::Antialiasing);

    pen.setColor(Qt::green);
    painter.setPen(pen);

    /*雷达距离刻度曲线*/
    painter.drawArc(100, 100, 1400, 1400, 0 * 16, 180 * 16);  // * 16相当于单位，是由于换算的原因
    painter.drawArc(240, 240, 1120, 1120, 0 * 16, 180 * 16);
    painter.drawArc(380, 380, 840, 840, 0 * 16, 180 * 16);
    painter.drawArc(520, 520, 560, 560, 0 * 16, 180 * 16);
    painter.drawArc(660, 660, 280, 280, 0 * 16, 180 * 16);
    painter.drawLine(QPoint(0, 800), QPoint(1600, 800));

    /*雷达角度刻度线*/
    painter.save();  // 保存坐标系
    painter.translate(800, 800);
    for(int i = 0; i < 5; ++i)
    {
        painter.rotate(-30);
        painter.drawLine(0, 0, 720, 0);
    }
    painter.restore();  // 恢复坐标系

    /*雷达角度刻度文字*/
    painter.save();
    QFont font("仿宋", 30, QFont::Bold, true);
    painter.setFont(font);
    painter.translate(800, 800);

    painter.drawText(720 * qCos(qDegreesToRadians(0.0)), -720 * qSin(qDegreesToRadians(0.0)), "0°");
    painter.drawText(720 * qCos(qDegreesToRadians(30.0)), -720 * qSin(qDegreesToRadians(30.0)), "30°");
    painter.drawText(720 * qCos(qDegreesToRadians(60.0)), -720 * qSin(qDegreesToRadians(60.0)), "60°");
    painter.drawText(720 * qCos(qDegreesToRadians(90.0)) - 20, -720 * qSin(qDegreesToRadians(90.0)), "90°");
    painter.drawText(720 * qCos(qDegreesToRadians(120.0)) - 60, -720 * qSin(qDegreesToRadians(120.0)), "120°");
    painter.drawText(720 * qCos(qDegreesToRadians(150.0)) - 80, -720 * qSin(qDegreesToRadians(150.0)), "150°");
    painter.drawText(720 * qCos(qDegreesToRadians(180.0)) - 80, -720 * qSin(qDegreesToRadians(180.0)), "180°");

    /*雷达距离刻度文字*/
    QString str[5] =
    {
        "10cm",
        "20cm",
        "30cm",
        "40cm",
        "50cm"
    };
    for(int i = 140, j = 0; i <= 700 && j <= 4; i += 140, ++j)
    {
        painter.drawText(i, 50, str[j]);
    }
    painter.restore();

    /*扫描线*/
    pen.setWidth(12);
    painter.setPen(pen);
    painter.save();
    painter.translate(800, 800);
    int x = int(700 * qCos(qDegreesToRadians(angle)));
    int y = int(-700 * qSin(qDegreesToRadians(angle)));
    painter.drawLine(0, 0, x, y);

    // 实现渐变拖尾的效果
    double d_angle = angle;
    if(flag == 0)
    {
        for(int num = 1; num <= d_angle; ++num)
        {
            painter.setOpacity(1 - num * 1.0 / (d_angle > 30.0 ? 30.0 : d_angle));
            x = int(700 * qCos(qDegreesToRadians(d_angle - num)));
            y = int(-700 * qSin(qDegreesToRadians(d_angle - num)));
            painter.drawLine(0, 0, x, y);
            if(num == 30) break;
        }
    }
    else if(flag == 1)
    {
        for(int num = 1; num <= (180 - d_angle); ++num)
        {
            painter.setOpacity(1 - num * 1.0 / ((180 - d_angle) > 30.0 ? 30.0 : (180 - d_angle)));
            x = int(700 * qCos(qDegreesToRadians(d_angle + num)));
            y = int(-700 * qSin(qDegreesToRadians(d_angle + num)));
            painter.drawLine(0, 0, x, y);
            if(num == 30) break;
        }
    }

    painter.restore();
}