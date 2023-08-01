#include "widget.h"
#include <QLabel>
#include <QPushButton>

widget::widget(QWidget *parent) : QWidget(parent)
{
    QLabel* label = new QLabel(this);
    label->setText("I love you, Rick!");
    label->move(120, 100);

    QPushButton* button = new QPushButton(this);
    button->setText("Close");
    button->move(130, 180);

//    label->show();  // 不属于任何窗体，只会在当前顶层窗口出现
//    label->setParent(this);
    setWindowTitle("MyFirstNoUI");
//    resize(400, 300);  // 可调的分辨率
    setFixedSize(400, 300);  // 不可调的分辨率
}

widget::~widget()
{

}
