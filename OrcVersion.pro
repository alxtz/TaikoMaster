#-------------------------------------------------
#
# Project created by QtCreator 2016-04-18T19:14:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OrcVersion
TEMPLATE = app


SOURCES += main.cpp \
    PlayView.cpp \
    PlayEngine.cpp \
    BlueDon.cpp \
    RedDon.cpp \
    HitPoint.cpp

HEADERS  += \
    PlayView.h \
    PlayEngine.h \
    BlueDon.h \
    RedDon.h \
    HitPoint.h

RESOURCES += \
    res.qrc
