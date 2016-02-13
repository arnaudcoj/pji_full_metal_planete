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
    game.cpp \
    player.cpp \
    tide.cpp \
    hightide.cpp \
    mediumtide.cpp \
    lowtide.cpp

HEADERS += \
    cell.h \
    piece.h \
    hexagrid.h \
    piecestock.h \
    game.h \
    player.h \
    tide.h \
    hightide.h \
    mediumtide.h \
    lowtide.h

LIBS += -L/usr/local/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIBS += -lyaml-cpp

INCLUDEPATH += \
    /usr/local/include
