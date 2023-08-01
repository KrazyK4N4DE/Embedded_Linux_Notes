#-------------------------------------------------
#
# Project created by QtCreator 2023-05-15T21:20:02
#
#-------------------------------------------------

QT       += core gui  # 添加类库

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyFirstWidget  # 目标生成的.exe文件名
TEMPLATE = app  # 生成一般应用


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
