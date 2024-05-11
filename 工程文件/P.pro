#-------------------------------------------------
#
# Project created by QtCreator 2020-06-29T12:44:13
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = P
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        p.cpp \
    parking.cpp \
    pass_change.cpp \
    car.cpp \
    line.cpp \
    lot.cpp \
    inline.cpp \
    inposi.cpp \
    outposi.cpp \
    check.cpp \
    all.cpp \
    fee.cpp

HEADERS += \
        p.h \
    parking.h \
    pass_change.h \
    car.h \
    line.h \
    lot.h \
    inline.h \
    inposi.h \
    outposi.h \
    check.h \
    all.h \
    fee.h

FORMS += \
        p.ui \
    parking.ui \
    pass_change.ui \
    inline.ui \
    inposi.ui \
    outposi.ui \
    check.ui \
    all.ui \
    fee.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
