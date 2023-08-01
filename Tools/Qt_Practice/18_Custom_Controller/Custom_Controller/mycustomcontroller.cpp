#include "mycustomcontroller.h"
#include "ui_mycustomcontroller.h"

MyCustomController::MyCustomController(QWidget *parent) : QWidget(parent), ui(new Ui::MyCustomController)
{
    ui->setupUi(this);

    void (QSpinBox::*spb)(int) = &QSpinBox::valueChanged;  // 信号函数若有重载，不知道到时会使用哪个，需使用函数指针指定
    connect(ui->spinBox, spb, ui->horizontalSlider, &QSlider::setValue);
    connect(ui->horizontalSlider, &QAbstractSlider::sliderMoved, ui->spinBox, &QSpinBox::setValue);
}

MyCustomController::~MyCustomController()
{
    delete ui;
}

int MyCustomController::get_Value(void)
{
    return ui->spinBox->value();
}
