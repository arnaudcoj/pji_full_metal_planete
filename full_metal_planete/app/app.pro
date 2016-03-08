TEMPLATE = app

CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

DEPENDPATH += .
INCLUDEPATH += .

# Input
SOURCES += \
    main.cpp

LIBS += -L/usr/local/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIBS += -L../api -lapi
LIBS += -L../interface -linterface

INCLUDEPATH += \
    /usr/local/include \
    ../api \
    ../interface

HEADERS +=
