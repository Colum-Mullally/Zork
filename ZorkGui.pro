#-------------------------------------------------
#
# Project created by QtCreator 2017-09-20T12:31:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZorkGui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        mainwindow.cpp \
    Character.cpp \
    item.cpp \
    Room.cpp \
    ZorkUL.cpp

HEADERS += \
        mainwindow.h \
    Character - Copy.h \
    Character.h \
    item.h \
    Room.h \
    ZorkUL.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    itemDetails.txt \
    4aTDsgTECUBfIjB0_nhZjelXP9wVmKKaOcbozI1wktQ.jpg \
    Zork.jpg

RESOURCES += \
    resource.qrc
