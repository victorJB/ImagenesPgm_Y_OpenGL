TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    matrix.cpp \
    pgm.cpp

HEADERS += \
    matrix.h \
    pgm.h

LIBS += -lfreeglut -lopengl32 -lglu32




