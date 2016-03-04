TEMPLATE = lib

CONFIG += c++11
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
    seacell.cpp \
    mountaincell.cpp \
    swampcell.cpp \
    reefcell.cpp \
    plaincell.cpp \
    engine.cpp \
    weapon.cpp

HEADERS += \
    cell.h \
    piece.h \
    hexagrid.h \
    piecestock.h \
    game.h \
    player.h \
    tide.h \
    gamestate.h \
    seacell.h \
    mountaincell.h \
    swampcell.h \
    reefcell.h \
    plaincell.h \
    engine.h \
    weapon.h

LIBS += -L/usr/local/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIBS += -lyaml-cpp

INCLUDEPATH += \
    /usr/local/include
