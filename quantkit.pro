
QT       += testlib

QT       -= gui

CONFIG   += c++11

TARGET = QuantKit
TEMPLATE = lib

DEFINES += QUANTKIT_LIBRARY

INCLUDEPATH += include

SOURCES +=

HEADERS +=\
        include/quantkit/quantkit_global.h \
    include/quantkit/event.h \
    include/quantkit/tick.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
