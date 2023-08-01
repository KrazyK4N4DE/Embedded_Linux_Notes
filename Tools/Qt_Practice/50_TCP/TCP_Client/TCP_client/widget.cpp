#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("客户端");
    tcpSocket = new QTcpSocket(this);

    /*设置默认值*/
    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_2->setText("8080");

    connect(tcpSocket, &QTcpSocket::readyRead, this, [&]()
    {
        QByteArray arr = tcpSocket->readAll();
        ui->textEdit->append("服务器：" + arr);
        ui->textEdit->setAlignment(Qt::AlignLeft);  // 服务器发的消息放在右边
        ui->textEdit_2->clear();  // 清空输入窗口
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    tcpSocket->connectToHost(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());
}

void Widget::on_pushButton_2_clicked()
{
    if(tcpSocket)
    {
        tcpSocket->write(ui->textEdit_2->toPlainText().toUtf8());
        ui->textEdit->append("客户端：" + ui->textEdit_2->toPlainText());  // 聊天记录上加东西
        ui->textEdit->setAlignment(Qt::AlignRight);  // 客户端发的消息放在右边
        ui->textEdit_2->clear();  // 清空输入窗口
    }
    else  // 没连接的话
    {
        qDebug() << "No connection!";
        return;
    }
}
