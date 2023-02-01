TEMPLATE = app
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtproj

INCLUDEPATH = src

SOURCES += \
           src/qtproj.cpp \
           src/main.cpp

HEADERS += src/qtproj.h

FORMS += src/qtproj.ui

RESOURCES += qtproj.qrc

LIBS += -lproj

# build dir
UI_DIR  =     build
MOC_DIR =     build
RCC_DIR =     build
OBJECTS_DIR = build
mytarget.commands += $${QMAKE_MKDIR} build
