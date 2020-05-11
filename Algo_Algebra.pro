TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        evklid.cpp \
        fibonacci.cpp \
        main.cpp \
        power.cpp

HEADERS += \
    evklid.h \
    fibonacci.h \
    itask.h \
    power.h \
    tester.h

LIBS += -lstdc++fs
