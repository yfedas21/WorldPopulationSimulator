#-------------------------------------------------
#
# Project created by QtCreator 2018-04-26T13:17:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WorldPopulationSimulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qsfmlcanvas.cpp

HEADERS += \
        mainwindow.h \
    globe.h \
    continent.h \
    disaster.h \
    simulation.h \
    sim_helper.h \
    qsfmlcanvas.h \
    qsfmlcanvas.h \
    SFMLanimation.h

FORMS += \
        mainwindow.ui


#SFML LIBRARY INCLUSION
INCLUDEPATH += $$PWD/includeSF
DEPENDPATH += $$PWD/includeSF

LIBS += -L$$PWD/..\LIBS\

CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-system-d -lsfml-main-d -lsfml-window-d -lsfml-graphics-d
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-system -lsfml-main -lsfml-window -lsfml-graphics
