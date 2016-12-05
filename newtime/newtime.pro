#-------------------------------------------------
#
# Project created by QtCreator 2016-11-28T23:36:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newtime
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pdfcanvas.cpp

HEADERS  += mainwindow.h \
    pdfcanvas.h

INCLUDEPATH += $$PWD/poppler
win32: LIBS += -L$$PWD/poppler -llibpoppler
win32: LIBS += -L$$PWD/poppler -llibpoppler-qt5
