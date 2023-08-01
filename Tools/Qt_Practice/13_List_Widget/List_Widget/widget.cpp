#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->addItem("你好");
    ui->listWidget->addItem("Hello");

    QListWidgetItem* listitem = new QListWidgetItem("I love you, Rick!");
    ui->listWidget->addItem(listitem);
    listitem->setTextAlignment(Qt::AlignHCenter);

    QStringList list2;
    list2 << "ABCD" << "EFGH" << "IJKL" << "MNOP";
    ui->listWidget_2->addItems(list2);
}

Widget::~Widget()
{
    delete ui;
}
