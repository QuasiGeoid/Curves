TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS+= -fopenmp
LIBS += -fopenmp

SOURCES += \
        curvegenerator.cpp \
        main.cpp

HEADERS += \
    curvegenerator.h

win32: LIBS += -L$$PWD/../curvesLib/ -lcurvesLib

INCLUDEPATH += $$PWD/../curvesLib
DEPENDPATH += $$PWD/../curvesLib
