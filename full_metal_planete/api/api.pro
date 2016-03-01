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
    seacell.cpp \
    mountaincell.cpp \
    swampcell.cpp \
    reefcell.cpp \
    tankpiece.cpp \
    weatherlayerpiece.cpp \
    bigtankpiece.cpp \
    patrolboatpiece.cpp \
    crabpiece.cpp \
    bargepiece.cpp \
    pontoonpiece.cpp \
    plaincell.cpp

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
    tankpiece.h \
    weatherlayerpiece.h \
    bigtankpiece.h \
    patrolboatpiece.h \
    crabpiece.h \
    bargepiece.h \
    pontoonpiece.h \
    plaincell.h

LIBS += -L/usr/local/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIBS += -lyaml-cpp

INCLUDEPATH += \
    /usr/local/include
