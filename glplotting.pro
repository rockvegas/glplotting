#-------------------------------------------------
#
# Project created by QtCreator 2015-11-09T15:15:37
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = glplotting
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    glplottingcanvas.cpp \
    plottingthread.cpp \
    tile.cpp \
    gleddialog.cpp

HEADERS  += widget.h \
    glplottingcanvas.h \
    plottingthread.h \
    tile.h \
    gleddialog.h
