TEMPLATE = lib

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
TARGET = api

SOURCES += \
    cell.cpp \
    piece.cpp \
    hexagrid.cpp

HEADERS += \
    cell.h \
    piece.h \
    hexagrid.h

LIBS += -L/usr/local/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

INCLUDEPATH += \
    /usr/local/include
