TEMPLATE = subdirs

CONFIG += ordered
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    ../api \
    ../interface

SUBDIRS += \
    app \
    api \
    tests \
    interface
