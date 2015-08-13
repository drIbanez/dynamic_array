TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXXFLAGS += -Wall -Wextra -Werror

SOURCES += main.cpp \
    tests.cpp

HEADERS += \
    Array.h \
    tests.h

