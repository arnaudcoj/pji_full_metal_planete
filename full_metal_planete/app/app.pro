TEMPLATE = app

DEPENDPATH += .
INCLUDEPATH += .

# Input
SOURCES += main.cpp

LIBS += -L/usr/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

LIBS += -L../api -lapi
INCLUDEPATH += \
    ../api
