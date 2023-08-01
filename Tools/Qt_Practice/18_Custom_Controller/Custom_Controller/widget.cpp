#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [&](){qDebug() << ui->widget->get_Value();});  // 自定义控件的对象名就是widget
}

Widget::~Widget()
{
    delete ui;
}
