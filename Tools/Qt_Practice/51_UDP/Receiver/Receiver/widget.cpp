#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("接收端");
    /*设置默认值*/
    ui->lineEdit->setText("127.0.0.1");

    receiver = new QUdpSocket(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    receiver->bind(ui->lineEdit_2->text().toInt());
    connect(receiver, &QUdpSocket::readyRead, this, [&]()
    {
        QByteArray arr;
        arr.resize(receiver->pendingDatagramSize());  // 开辟内存空间
        receiver->readDatagram(arr.data(), receiver->pendingDatagramSize());
        ui->textEdit->append("发送者：" + arr);
        ui->textEdit->setAlignment(Qt::AlignRight);
    });
    ui->pushButton_2->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
}

void Widget::on_pushButton_clicked()
{
    QByteArray arr = ui->textEdit_2->toPlainText().toUtf8();
    receiver->writeDatagram(arr.data(), arr.size(), QHostAddress(ui->lineEdit->text()), ui->lineEdit_3->text().toInt());
    ui->textEdit->append("接收者：" + arr);
    ui->textEdit->setAlignment(Qt::AlignLeft);
    ui->textEdit_2->clear();
}
