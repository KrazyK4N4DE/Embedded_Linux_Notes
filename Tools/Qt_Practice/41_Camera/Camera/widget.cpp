#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if(cameras.count() > 0)
    {
        foreach (const QCameraInfo &cameraInfo, cameras)
            qDebug() << cameraInfo.deviceName();
        camera = new QCamera(cameras.at(0));  // 打开设备中的第一个摄像头设备
    }
    viewfinder = new QCameraViewfinder(this);
    viewfinder->resize(600, 350);
    camera->setViewfinder(viewfinder);
    imageCapture = new QCameraImageCapture(camera);
    camera->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    camera->setCaptureMode(QCamera::CaptureStillImage);
    QString filename = QFileDialog::getSaveFileName();
    imageCapture->capture(filename);
}
