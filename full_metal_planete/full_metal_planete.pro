TEMPLATE = subdirs

CONFIG += ordered
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    ../api

SUBDIRS += \
    app \
    api \
    tests
