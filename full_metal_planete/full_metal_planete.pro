TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIBS += -L/usr/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

INCLUDEPATH = usr/include
