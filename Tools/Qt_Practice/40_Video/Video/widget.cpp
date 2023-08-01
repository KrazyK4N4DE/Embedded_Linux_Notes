#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    videowidget = new QVideoWidget(this);  // QVideoWidget默认可以播放wmv，但不支持mp4，需要下载库
    videowidget->resize(600, 300);
    player->setVideoOutput(videowidget);  // player才是真正播放视频的

    connect(player, &QMediaPlayer::durationChanged, this, &Widget::getDuration);  // 获取视频长度的信号与槽
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &Widget::sliderChanged);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::getDuration(void)
{
    ui->horizontalSlider->setMaximum(player->duration());
}

void Widget::sliderChanged(void)
{
    pos = ui->horizontalSlider->value();
    player->setPosition(pos);
}

void Widget::on_pushButton_clicked()
{
    filename = QFileDialog::getOpenFileName(this, "Open File", "../");
    player->setMedia(QUrl::fromLocalFile(filename));
}

void Widget::on_pushButton_2_clicked()
{
    player->play();
}

void Widget::on_pushButton_3_clicked()
{
    player->pause();
}

void Widget::on_pushButton_4_clicked()
{
    player->stop();
}
