#-------------------------------------------------
#
# Project created by QtCreator 2017-06-04T16:59:33
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExpressBaseManagement
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    dialoglogin.cpp \
    mainwindowui.cpp \
    windowconsumerinfo.cpp \
    windowapplyorder.cpp \
    windowapplygoods.cpp \
    windowchangegoods.cpp \
    windowreapplygoods.cpp \
    windowstore.cpp \
    windowstoreinfo.cpp \
    windowchangeorder.cpp \
    windowpredictresult.cpp \
    windoworderinfo.cpp \
    windowexpressinfo.cpp \
    staticsui.cpp \
    staticsdeal.cpp \
    staticsconsumer.cpp \
    tickets.cpp \
    superpower.cpp \
    adminuser.cpp \
    advancedop.cpp

HEADERS  += mainwindow.h \
    dialoglogin.h \
    head.h \
    mainwindowui.h \
    windowconsumerinfo.h \
    windowapplyorder.h \
    windowapplygoods.h \
    windowchangegoods.h \
    windowreapplygoods.h \
    windowstore.h \
    windowstoreinfo.h \
    windowchangeorder.h \
    windowpredictresult.h \
    windoworderinfo.h \
    windowexpressinfo.h \
    staticsui.h \
    staticsdeal.h \
    staticsconsumer.h \
    tickets.h \
    superpower.h \
    adminuser.h \
    advancedop.h

FORMS    += mainwindow.ui \
    dialoglogin.ui \
    mainwindowui.ui \
    windowconsumerinfo.ui \
    windowapplyorder.ui \
    windowapplygoods.ui \
    windowchangegoods.ui \
    windowreapplygoods.ui \
    windowstore.ui \
    windowstoreinfo.ui \
    windowchangeorder.ui \
    windowpredictresult.ui \
    windoworderinfo.ui \
    windowexpressinfo.ui \
    staticsui.ui \
    staticsdeal.ui \
    staticsconsumer.ui \
    tickets.ui \
    superpower.ui \
    adminuser.ui \
    advancedop.ui
