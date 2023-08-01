#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [&]()
    {
        QString fileName = QFileDialog::getOpenFileName(this, "打开文件", "D:/Warehouse");
        ui->lineEdit->setText(fileName);

        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
//        QByteArray array = file.readAll();
        QByteArray array;
        while(!file.atEnd()) array += file.readLine();

        ui->textEdit->setText(array);  // QByteArray可以隐式转换为QString
        file.close();

        file.open(QIODevice::Append);
        file.write("\nI love U");
        file.close();
    });
}

Widget::~Widget()
{
    delete ui;
}
