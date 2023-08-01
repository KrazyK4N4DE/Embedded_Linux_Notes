#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myclass1.h"
#include "myclass2.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    MyClass1* mc1;
    MyClass2* mc2;

    int num = 0;
};

#endif // WIDGET_H
