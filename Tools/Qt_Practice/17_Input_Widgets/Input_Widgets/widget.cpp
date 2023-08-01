#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItems(QStringList() << "博士" << "硕士" << "本科" << "专科" << "高中及以下");

    connect(ui->pushButton, &QPushButton::clicked, this, [&](){ui->label->setFont(QFont(ui->fontComboBox->currentFont()));});

    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->timeEdit->setTime(curDateTime.time());
    ui->dateTimeEdit->setDateTime(curDateTime);
}

Widget::~Widget()
{
    delete ui;
}
