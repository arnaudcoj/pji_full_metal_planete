TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    testHexagrid.cpp \
    main.cpp

HEADERS += \
    catch.hpp

INCLUDEPATH += \
    ../api

LIBS += -L../api -lapi

DISTFILES +=
