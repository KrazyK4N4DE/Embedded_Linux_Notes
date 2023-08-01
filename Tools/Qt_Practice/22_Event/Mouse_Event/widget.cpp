#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>

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

bool Widget::event(QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "鼠标按键被按下";
        return true;
    }
    return QWidget::event(event);  // 返回给父类的默认event函数处理，这样除了鼠标按压被拦截处理，其它都正常
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "Mouse LeftButton pressed\n" << "x = " << event->x() << ", y = " << event->y();
        qDebug() << "GlobalX = " << event->globalX() << ", GlobalY = " << event->globalY();
    }
    else if(event->button() == Qt::RightButton)
    {
        qDebug() << "Mouse RightButton pressed\n" << "x = " << event->x() << ", y = " << event->y();
        qDebug() << "GlobalX = " << event->globalX() << ", GlobalY = " << event->globalY();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Button is released";
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        // windowState() != Qt::WindowFullScreen ? setWindowState(Qt::WindowFullScreen) : setWindowState(Qt::WindowNoState);
        setWindowState(windowState() ^ Qt::WindowFullScreen);  // 上面的简化写法
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)  // 检测含没含左键
    {
        QPoint tmp;
        tmp = event->globalPos() - pos;  // 鼠标位置和当前窗体位置差多少，就move多少
        move(tmp);
    }
}

void Widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)  // delta()：滚轮滚的值
        ui->textEdit->zoomIn();
    else if(event->delta() < 0)
        ui->textEdit->zoomOut();
}
