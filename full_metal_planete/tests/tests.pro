TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    testHexagrid.cpp \
    main.cpp \
    testCell.cpp \
    testpiecestock.cpp \
    testplayer.cpp

HEADERS += \
    catch.hpp

LIBS += -L/usr/local/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

LIBS += -L../api -lapi

LIBS += -lyaml-cpp

INCLUDEPATH += \
    /usr/local/include \
    ../api
