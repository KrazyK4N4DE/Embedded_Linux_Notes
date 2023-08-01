#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("../Audio/sounds_sfx 14640.mp3"));  // 播放本地
    player->setVolume(20);  // 音量

    effect = new QSoundEffect(this);
    effect->setSource(QUrl::fromLocalFile("../Audio/清晨鸟鸣声.wav"));
    effect->setVolume(0.5);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    player->play();
}

void Widget::on_pushButton_2_clicked()
{
    player->stop();
}

void Widget::on_pushButton_3_clicked()
{
    effect->play();
}

void Widget::on_pushButton_4_clicked()
{
    effect->stop();
}
