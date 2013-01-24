TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += link_pkgconfig
PKGCONFIG += sdl

SOURCES += src/main.cpp \
    src/scroll_engine.cpp

HEADERS += \
    src/scroll_engine.h

