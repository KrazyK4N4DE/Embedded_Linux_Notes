#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QDebug>

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

        /*改用文本流*/
        QTextStream stream(&file);
        stream.setCodec("utf-8");  // 改编码格式
        QByteArray array;
        while(!stream.atEnd()) array += stream.readLine();

        ui->textEdit->setText(array);  // QByteArray可以隐式转换为QString
        file.close();

//        file.open(QIODevice::Append);
//        file.write("\nI love U");
//        file.close();
    });

    /*数据流*/
    QFile file("D:/Warehouse/file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream data_stream(&file);
    data_stream << QString("Good evening ") << (qint32)65;
    file.close();
    file.open(QIODevice::ReadOnly);
    QDataStream data_in_stream(&file);
    QString str;
    qint32 n;
    data_in_stream >> str >> n;
    qDebug() << "str = " << str << ", n = " << n;
    file.close();

    /*用数据流将内容放入内存空间*/
    QImage img("D:/pic.jpg");
    QByteArray arr;  // 开辟一块内存空间
    QDataStream stream(&arr, QIODevice::ReadWrite);  // 将数据流和内存空间绑定起来
    stream << img;  // 将图片信息放入内存空间中
}

Widget::~Widget()
{
    delete ui;
}
