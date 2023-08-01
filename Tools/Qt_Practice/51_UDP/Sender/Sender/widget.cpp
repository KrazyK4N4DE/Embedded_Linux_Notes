#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("发送端");
    /*设置默认值*/
    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_3->setText("8888");

    sender = new QUdpSocket(this);
    sender->bind(ui->lineEdit_3->text().toInt());  // 绑定端口

    connect(sender, &QUdpSocket::readyRead, this, [&]()
    {
        QByteArray arr;
        arr.resize(sender->pendingDatagramSize());  // 开辟内存空间
        sender->readDatagram(arr.data(), arr.size());
        ui->textEdit->append("接收者：" + arr);
        ui->textEdit->setAlignment(Qt::AlignLeft);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QByteArray arr = ui->textEdit_2->toPlainText().toUtf8();
    sender->writeDatagram(arr.data(), arr.size(), QHostAddress(ui->lineEdit->text()), ui->lineEdit_2->text().toInt());
    ui->textEdit->append("发送者：" + arr);
    ui->textEdit->setAlignment(Qt::AlignRight);
    ui->textEdit_2->clear();
}
