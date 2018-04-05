TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -static

SOURCES += main.cpp \
    exception.cpp \
    testcexception.cpp

HEADERS += \
    exception.h
