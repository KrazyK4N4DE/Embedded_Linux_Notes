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

private:
    Ui::Widget *ui;
    QPoint pos;  // 窗体当前零点(左上角)的位置

protected:
    bool event(QEvent *event);
    /*事件处理*/
    virtual void mousePressEvent(QMouseEvent *event);  // 鼠标按压
    void mouseReleaseEvent(QMouseEvent *event);  // 鼠标释放
    void mouseDoubleClickEvent(QMouseEvent *event);  // 双击全屏
    void mouseMoveEvent(QMouseEvent *event);  // 左键按住拖动时窗体跟随移动
    void wheelEvent(QWheelEvent *event);  // 滚轮
};

#endif // WIDGET_H
