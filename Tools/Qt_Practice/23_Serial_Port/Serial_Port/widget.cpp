#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(1366, 768);
    setWindowTitle("串口调试助手");

    /*定时检查是否有可用的COM口*/
    timer = new QTimer(this);
    timer->start(500);  // 500ms
    connect(timer, &QTimer::timeout, this, &Widget::TimerEvent);

    serial = new QSerialPort(this);

    ui->comboBox_2->setCurrentIndex(5);
    ui->comboBox_3->setCurrentIndex(3);
    ui->comboBox_4->setCurrentIndex(2);
    ui->comboBox_5->setCurrentIndex(0);
    receivceByteNum = 0;
    sendByteNum = 0;

    connect(serial, &QSerialPort::readyRead, this, &Widget::serialPort_readyRead);
    ui->checkBox->setCheckState(Qt::Checked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::TimerEvent(void)
{
    QStringList newPortStringList;
    foreach(const QSerialPortInfo& info, QSerialPortInfo::availablePorts())
        newPortStringList += info.portName();

    if(newPortStringList.size() != portStringList.size())  // 串口号列表如果都一样就不要再加了，防止串口号一直增加
    {
        portStringList = newPortStringList;
        ui->comboBox->clear();
        ui->comboBox->addItems(portStringList);
    }
}

void Widget::on_pushButton_clicked()
{
    if(ui->pushButton->text() == QString("打开串口"))
    {
        /*设置串口号*/
        serial->setPortName(ui->comboBox->currentText());
        serial->setBaudRate(ui->comboBox_2->currentText().toInt());  // 设置波特率
        /*设置数据位*/
        switch(ui->comboBox_3->currentText().toInt())
        {
        case 5: serial->setDataBits(QSerialPort::Data5); break;
        case 6: serial->setDataBits(QSerialPort::Data6); break;
        case 7: serial->setDataBits(QSerialPort::Data7); break;
        case 8: serial->setDataBits(QSerialPort::Data8); break;
        default: serial->setDataBits(QSerialPort::UnknownDataBits); break;
        }
        /*设置校验位，用下标索引判断*/
        switch(ui->comboBox_4->currentIndex())
        {
        case 0: serial->setParity(QSerialPort::EvenParity); break;
        case 1: serial->setParity(QSerialPort::OddParity); break;
        case 2: serial->setParity(QSerialPort::NoParity); break;
        default: serial->setParity(QSerialPort::UnknownParity); break;
        }
        /*设置停止位*/
        switch(ui->comboBox_5->currentIndex())
        {
        case 0: serial->setStopBits(QSerialPort::OneStop); break;
        case 1: serial->setStopBits(QSerialPort::OneAndHalfStop); break;
        case 2: serial->setStopBits(QSerialPort::TwoStop); break;
        default: serial->setStopBits(QSerialPort::UnknownStopBits); break;
        }
        /*设置流量控制*/
        serial->setFlowControl(QSerialPort::NoFlowControl);
        /*打开串口*/
        if(!serial->open(QIODevice::ReadWrite))
        {
            QMessageBox::information(this, "错误提示", "打开串口失败！", QMessageBox::Ok);
            return;
        }
        /*打开之后设定comboBox不能选*/
        ui->comboBox->setEnabled(false);
        ui->comboBox_2->setEnabled(false);
        ui->comboBox_3->setEnabled(false);
        ui->comboBox_4->setEnabled(false);
        ui->comboBox_5->setEnabled(false);

        ui->pushButton->setText("关闭串口");
    }
    else
    {
        serial->close();

        ui->comboBox->setEnabled(true);
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->comboBox_4->setEnabled(true);
        ui->comboBox_5->setEnabled(true);

        ui->pushButton->setText("打开串口");
    }
}

void Widget::serialPort_readyRead(void)
{
    QString lastText;
    int length;
    int i;
    if(ui->checkBox_3->checkState() != Qt::Checked)
    {
        lastText = ui->textEdit->toPlainText();
        receiveText = serial->readAll();
        receivceByteNum += receiveText.length();
        ui->label_9->setText(QString::number(receivceByteNum));

        if(ui->checkBox_2->checkState() == Qt::Checked)  // hex
        {
            receiveText = receiveText.toLatin1().toHex();
            length = receiveText.length();
            for(i = 0; i <= length / 2; ++i)
                receiveText.insert(2 + 3 * i, ' ');  // 给每两个字节加一个空格，分隔数据好看些
        }
        else  // ASCII
        {
            receiveText = receiveText.toLatin1();
        }
        lastText = lastText.append(receiveText);  // 保证EditText能一直往下刷，而不是重复刷新
        ui->textEdit->setText(lastText);
    }
}

void Widget::on_checkBox_clicked()
{
    ui->checkBox->setCheckState(Qt::Checked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
    ui->checkBox_3->setCheckState(Qt::Unchecked);
}

void Widget::on_checkBox_2_clicked()
{
    ui->checkBox_2->setCheckState(Qt::Checked);
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->checkBox_3->setCheckState(Qt::Unchecked);
}

void Widget::on_checkBox_3_clicked()
{
    ui->checkBox_3->setCheckState(Qt::Checked);
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
}

void Widget::on_pushButton_2_clicked()
{
    QByteArray byteArray;
    sendText = ui->textEdit_2->toPlainText();  // 获取textEdit里的内容
    byteArray = sendText.toLatin1();
    serial->write(byteArray);  // 发送数据
    sendByteNum += sendText.length();
    ui->label_10->setText(QString::number(sendByteNum));
}

void Widget::on_pushButton_3_clicked()
{
    ui->textEdit->clear();
}

void Widget::on_pushButton_4_clicked()
{
    ui->textEdit_2->clear();
}
