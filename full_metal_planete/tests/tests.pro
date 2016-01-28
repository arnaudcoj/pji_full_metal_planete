TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    testHexagrid.cpp \
    main.cpp

HEADERS += \
    catch.hpp

LIBS += -L/usr/local/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

LIBS += -L../api -lapi
INCLUDEPATH += \
    /usr/local/include \
    ../api
