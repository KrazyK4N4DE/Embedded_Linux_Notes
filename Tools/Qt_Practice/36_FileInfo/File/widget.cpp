#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

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

    /*文件信息*/
    QFile file("D:/Warehouse/test.txt");
    QFileInfo info(file);
    qDebug() << "绝对路径：" << info.absoluteFilePath();
    qDebug() << "文件名：" << info.fileName();
    qDebug() << "后缀名：" << info.suffix();
    qDebug() << "创建时间：" << info.created().toString("dd.MM.yyyy hh:mm:ss");
    qDebug() << "文件大小：" << info.size();

    file.open(QIODevice::ReadOnly);
    file.seek(0);
    QByteArray array = file.read(5);  // 前5个
    qDebug() << "前5个字节：" << array;
    qDebug() << "当前光标位置：" << file.pos();
    file.seek(15);
    array = file.read(5);
    qDebug() << "第16到第20个字节：" << array;
    qDebug() << "当前光标位置：" << file.pos();
    file.close();
}

Widget::~Widget()
{
    delete ui;
}
