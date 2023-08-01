#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("接收端");

    ui->lineEdit->setText("8080");  // 设置默认端口为8080

    tcpServer = new QTcpServer(this);
    /*监听本地网络*/
    tcpServer->listen(QHostAddress::LocalHost, ui->lineEdit->text().toInt());
    /*收到newConnection信号，产生新的套接字，服务器向客户端发送消息：write*/

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    connect(tcpServer, &QTcpServer::newConnection, this, [&]()
    {
        clientConnection = tcpServer->nextPendingConnection();  // 产生套接字
        clientConnection->write("Welcome to connect to the server!");  // 服务器向客户端发送消息

        /*服务端和客户端连接后才产生套接字，服务器才能收到客户端的消息：readyRead*/
        connect(clientConnection, &QTcpSocket::readyRead, this, [&]()
        {
            QByteArray arr = clientConnection->readAll();
            if(headerInfo)  // 处理头信息
            {
                headerInfo = false;
                receiveSize = 0;
                /*用section鉴别分隔符*/
                fileName = QString(arr).section("**", 0, 0);
                fileSize = QString(arr).section("**", 1, 1).toInt();
                /*打开文件*/
                file.setFileName(fileName);
                file.open(QIODevice::WriteOnly);  // 因为服务端这边可能没有文件的，所以没有就创建一个，然后接收数据过来

                /*初始化进度条*/
                ui->progressBar->setMinimum(0);
                ui->progressBar->setMaximum(fileSize / 1024);
                ui->progressBar->setValue(0);
            }
            else  // 收传过来的数据
            {
                qint64 len = file.write(arr);
                if(len > 0) receiveSize += len;
                ui->progressBar->setValue(receiveSize / 1024);  // 更新进度条
                if(receiveSize == fileSize)  // 当传过来的内容大小和文件大小一致时，说明传完了
                {
                    QMessageBox::information(this, "Finished", "文件传输完成");
                    file.close();
                }
            }
        });
    });
    ui->pushButton->setEnabled(false);
}
