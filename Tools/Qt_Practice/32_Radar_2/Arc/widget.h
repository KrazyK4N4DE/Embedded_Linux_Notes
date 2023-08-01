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
    void paintEvent(QPaintEvent*);

public slots:
    void timerTimeOut(void);

private:
    Ui::Widget *ui;
    double angle = 0.0;
};

#endif // WIDGET_H
