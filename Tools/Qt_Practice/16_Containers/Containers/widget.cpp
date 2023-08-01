#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(2);  // 设置默认的显示区
    connect(ui->ScrollArea, &QPushButton::clicked, this, [&](){ui->stackedWidget->setCurrentIndex(0);});
    connect(ui->ToolBox, &QPushButton::clicked, this, [&](){ui->stackedWidget->setCurrentIndex(1);});
    connect(ui->TabWidget, &QPushButton::clicked, this, [&](){ui->stackedWidget->setCurrentIndex(2);});
}

Widget::~Widget()
{
    delete ui;
}
