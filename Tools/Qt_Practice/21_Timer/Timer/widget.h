#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void timerEvent(QTimerEvent *event);  // 重载定时器事件处理函数

private:
    Ui::Widget *ui;
    int time_id1;
    int time_id2;
};

#endif // WIDGET_H
