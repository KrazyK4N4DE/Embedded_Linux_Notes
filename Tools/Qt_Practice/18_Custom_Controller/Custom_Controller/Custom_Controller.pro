#-------------------------------------------------
#
# Project created by QtCreator 2023-05-21T22:35:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Custom_Controller
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mycustomcontroller.cpp

HEADERS  += widget.h \
    mycustomcontroller.h

FORMS    += widget.ui \
    mycustomcontroller.ui
