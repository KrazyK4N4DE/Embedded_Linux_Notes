#-------------------------------------------------
#
# Project created by QtCreator 2023-05-16T22:12:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Signal_Slot
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    myclass1.cpp \
    myclass2.cpp

HEADERS  += widget.h \
    myclass1.h \
    myclass2.h

FORMS    += widget.ui
