TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    matrix.cpp \
    pgm.cpp \
    opImagen.cpp

HEADERS += \
    matrix.h \
    pgm.h \
    opImagen.h

LIBS += -lfreeglut -lopengl32 -lglu32
#LIBS += -lm -lGL -lglut -lGLU




