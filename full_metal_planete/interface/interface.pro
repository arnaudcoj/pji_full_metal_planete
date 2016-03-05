TEMPLATE = lib

CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt
TARGET = interface

SOURCES += \
    grid.cpp \
    hexagon.cpp \
    pawn.cpp \
    assetmanager.cpp

HEADERS += \
    grid.h \
    hexagon.h \
    pawn.h \
    assetmanager.h

LIBS += -L/usr/local/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIBS += -L../api -lapi

INCLUDEPATH += \
    /usr/local/include \
    ../api
