TEMPLATE = lib

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
TARGET = api

SOURCES += \
    cell.cpp \
    piece.cpp \
    piecestock.cpp \
    game.cpp \
    player.cpp \
    hexagrid.cpp \
    gamestate.cpp \
    hillcell.cpp

HEADERS += \
    cell.h \
    piece.h \
    hexagrid.h \
    piecestock.h \
    game.h \
    player.h \
    tide.h \
    gamestate.h \
    hillcell.h

LIBS += -L/usr/local/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIBS += -lyaml-cpp

INCLUDEPATH += \
    /usr/local/include
