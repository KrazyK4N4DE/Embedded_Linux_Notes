#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QDebug>
#include <QPushButton>

#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>

#include <QMessageBox>
#include <QProgressDialog>
#include <QErrorMessage>
#include <QWizard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    errdlg = new QErrorMessage(this);
    resize(800, 600);

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

void MainWindow::on_pushButton_5_clicked()
{
    // 问题对话框
    int ret1 = QMessageBox::question(this, "问题", "你是否使用Qt？", QMessageBox::Yes, QMessageBox::No);
    if(ret1 == QMessageBox::Yes)
        qDebug() << "Great";

    // 提示对话框
    QMessageBox::information(this, "提示", "你最好使用Qt", QMessageBox::Ok);

    // 警告对话框
    QMessageBox::warning(this, "警告", "请停止使用其它GUI", QMessageBox::Ok);

    // 错误对话框
    QMessageBox::critical(this, "错误", "你做了错饭", QMessageBox::Retry);

    // 关于对话框
    QMessageBox::about(this, "关于", "我爱Rick");
}

void MainWindow::on_pushButton_6_clicked()
{
    QProgressDialog pgdlg("复制内容", "取消", 0, 50000, this);
    pgdlg.setWindowTitle("复制文件");
    pgdlg.setWindowModality(Qt::WindowModal);  // 模态化，不希望进度时其他窗口能动
    pgdlg.show();
    // 进度条实现
    for(int i = 0; i < 50000; ++i)
    {
        pgdlg.setValue(i);
        QCoreApplication::processEvents();  // 使在进度过程中同时检查有没有其他事情要处理
        if(pgdlg.wasCanceled()) break;
    }
    pgdlg.setValue(50000);
    qDebug() << "拷贝完成";
}

void MainWindow::on_pushButton_7_clicked()
{
    errdlg->setWindowTitle("错误");
    errdlg->showMessage("危险");
}

QWizardPage* createPage1(void)
{
    QWizardPage* page = new QWizardPage;
    page->setTitle("Step1");
    return page;
}
QWizardPage* createPage2(void)
{
    QWizardPage* page = new QWizardPage;
    page->setTitle("Step2");
    return page;
}

void MainWindow::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle("向导");
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.exec();
}
