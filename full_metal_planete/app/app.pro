 TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEPENDPATH += .
INCLUDEPATH += .

# Input
SOURCES += main.cpp

LIBS += -L/usr/local/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

LIBS += -L../api -lapi

LIBS += -lyaml-cpp

INCLUDEPATH += \
    /usr/local/include \
    ../api
