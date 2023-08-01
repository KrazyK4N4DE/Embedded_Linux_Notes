#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("服务端");

    ui->lineEdit->setText("8080");  // 设置默认端口为8080

    tcpServer = new QTcpServer(this);
    /*监听本地网络*/
    tcpServer->listen(QHostAddress::LocalHost, ui->lineEdit->text().toInt());
    /*收到newConnection信号，产生新的套接字，服务器向客户端发送消息：write*/
    connect(tcpServer, &QTcpServer::newConnection, this, [&]()
    {
        clientConnection = tcpServer->nextPendingConnection();  // 产生套接字
        clientConnection->write("Welcome to connect to the server!");  // 服务器向客户端发送消息
        ui->textEdit->append("New connection......");

        /*服务端和客户端连接后才产生套接字，服务器才能收到客户端的消息：readyRead*/
        connect(clientConnection, &QTcpSocket::readyRead, this, [&]()
        {
            QByteArray arr = clientConnection->readAll();
            ui->textEdit->append("客户端：" + arr);
            ui->textEdit->setAlignment(Qt::AlignRight);  // 客户端消息放右边
        });
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(clientConnection)
    {
        clientConnection->write(ui->textEdit_2->toPlainText().toUtf8());
        ui->textEdit->append("服务器：" + ui->textEdit_2->toPlainText());  // 聊天记录上加东西
        ui->textEdit->setAlignment(Qt::AlignLeft);  // 服务器发的消息放在左边
        ui->textEdit_2->clear();  // 清空输入窗口
    }
    else  // 没连接的话
    {
        qDebug() << "No connection!";
        return;
    }
}
