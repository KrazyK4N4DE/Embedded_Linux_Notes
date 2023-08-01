#include "widget.h"
#include "ui_widget.h"
#include "myclass.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyClass* mc = new MyClass(this);

    ui->toolButton->setIcon(QIcon(":/Images/Images/goku.png"));  // 给toolButton加载图标
    ui->rB_grade1->setChecked(true);  // radioButton默认勾选
    /*信号和槽*/
    connect(ui->rB_score5, &QRadioButton::clicked, mc, &MyClass::MySlot);
}

Widget::~Widget()
{
    delete ui;
}
