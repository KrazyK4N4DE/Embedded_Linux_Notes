#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QDebug>
#include <QPushButton>

#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 添加Qt资源文件使用格式 ": + 前缀 + 文件名"
    ui->actionNew->setIcon(QIcon(":/Images/star.ico"));
    ui->actionOpen->setIcon(QIcon(":/Images/python.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this);
    qDebug() << "Color: " << color;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "D:/", "图片(*.png *.jpg)");
    qDebug() << "fileName: " << fileName;
}

void MainWindow::on_pushButton_3_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
        ui->pushButton_3->setFont(font);
    else qDebug() << "No Font!";
}

void MainWindow::on_pushButton_4_clicked()
{
    bool ok;
    QString string = QInputDialog::getText(this, "输入字符串对话框", "用户名：", QLineEdit::Normal, nullptr, &ok);
    if(ok)
        qDebug() << "string: " << string;

    int value = QInputDialog::getInt(this, "输入整数对话框", "0~100 Please", 0, 0, 100, 1, &ok);
    if(ok)
        qDebug() << "Value = " << value;
}
