#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("传文件");
    tcpSocket = new QTcpSocket(this);

    /*设置默认值*/
    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_2->setText("8080");

    connect(tcpSocket, &QTcpSocket::readyRead, this, [&]()
    {
        QByteArray arr = tcpSocket->readAll();
        qDebug() << "服务器：" << arr;
    });

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [&]()
    {
        timer->stop();
        qint64 len;
        qint64 sendTotalSize = 0;
        do
        {
            char buf[4*1024] = {0};  // 创建一个缓冲区buf
            len = 0;
            len = file.read(buf, sizeof(buf));  // 读出缓冲区大小的内容放到buf中，并返回读出的字节大小
            tcpSocket->write(buf, len);  // 通过套接字将buf传输到服务端 (这里len不能写为sizeof(buf))
            sendTotalSize += len;
            ui->progressBar->setValue(sendTotalSize / 1024);  // 更新进度条
        }while(len > 0);
        if(sendTotalSize == fileSize)  // 当传过去的内容大小和文件大小一致时，说明传完了
        {
            file.close();
            tcpSocket->disconnectFromHost();
            tcpSocket->close();
        }
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
    QString filePath = QFileDialog::getOpenFileName(this);  // 文件路径
    QFileInfo fileData(filePath);
    fileName = fileData.fileName();
    fileSize = fileData.size();

    qDebug() << "file name: " << fileName;
    qDebug() << "file size: " << fileSize;

    /*用QFile打开文件*/
    if(!filePath.isEmpty())
    {
        ui->label_3->setText(filePath);
        file.setFileName(filePath);
        file.open(QIODevice::ReadOnly);
    }

    /*设置进度条*/
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(fileSize / 1024);
    ui->progressBar->setValue(0);
}

/*发送文件数据格式："我的小苹果**3132566"*/
void Widget::on_pushButton_3_clicked()
{
    QString header = fileName + "**" + QString::number(fileSize);
    qint64 length = tcpSocket->write(header.toUtf8());
    if(length > 0)  // 发送成功
        timer->start(20);  // 使用定时器是为了防止连续发送，两个数据连在一起，不好解析
    else file.close();
}
