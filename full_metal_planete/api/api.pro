TEMPLATE = lib

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
TARGET = api

SOURCES += \
    cell.cpp \
    piece.cpp \
    hexagrid.cpp \
    piecestock.cpp \
    game.cpp

HEADERS += \
    cell.h \
    piece.h \
    hexagrid.h \
    piecestock.h \
    game.h

INCLUDEPATH += \
    /usr/local/include
