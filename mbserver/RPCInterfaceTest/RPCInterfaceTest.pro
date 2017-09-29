QT += testlib
QT += network core
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += \
    ../mediablocksd/include \
    ../../libmediablocks/mediablocks/include

SOURCES += \
    ../mediablocksd/src/interface.cpp \
    ../mediablocksd/src/rpcinterface.cpp \
    rpcinterfacetest.cpp

HEADERS += \
    ../mediablocksd/include/interface.hpp \
    ../mediablocksd/include/rpcinterface.hpp \
    ../mediablocksd/include/mediablocks.hpp

