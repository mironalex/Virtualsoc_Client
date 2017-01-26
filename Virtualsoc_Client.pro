#-------------------------------------------------
#
# Project created by QtCreator 2017-01-03T02:23:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Virtualsoc_Client
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


SOURCES += main.cpp \
    mainwindow.cpp \
    clientinterface.cpp \
    registerwindow.cpp \
    utilities.cpp \
    friendmanager.cpp \
    conversationwindow.cpp \
    group_conversationwindow.cpp \
    conversation_manager.cpp

HEADERS  += \
    client.h \
    mainwindow.h \
    clientinterface.h \
    registerwindow.h \
    utilities.h \
    friendmanager.h \
    conversationwindow.h \
    group_conversationwindow.h \
    conversation_manager.h

FORMS    += \
    mainwindow.ui \
    clientinterface.ui \
    registerwindow.ui \
    friendmanager.ui \
    conversationwindow.ui \
    group_conversationwindow.ui \
    conversation_manager.ui
