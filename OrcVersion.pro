#-------------------------------------------------
#
# Project created by QtCreator 2016-04-18T19:14:26
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OrcVersion
TEMPLATE = app


SOURCES += main.cpp \
    PlayView.cpp \
    PlayEngine.cpp \
    BlueDon.cpp \
    RedDon.cpp \
    HitPoint.cpp \
    GreatIcon.cpp \
    GoodIcon.cpp \
    BadIcon.cpp \
    Note.cpp \
    SheetMusic.cpp \
    SheetMusicPlayer.cpp \
    Drum.cpp \
    SmallDrum.cpp \
    ScoreNow.cpp \
    PercentNow.cpp \
    Combo.cpp

HEADERS  += \
    PlayView.h \
    PlayEngine.h \
    BlueDon.h \
    RedDon.h \
    HitPoint.h \
    GreatIcon.h \
    GoodIcon.h \
    BadIcon.h \
    Note.h \
    SheetMusic.h \
    SheetMusicPlayer.h \
    Drum.h \
    SmallDrum.h \
    ScoreNow.h \
    PercentNow.h \
    Combo.h

RESOURCES += \
    res.qrc
