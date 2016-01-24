TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
TARGET = api

SOURCES += \
    Hexagrid.cpp

HEADERS += \
    Hexagrid.h

LIBS += -L/usr/lib -lsfml-system
