TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += link_pkgconfig
PKGCONFIG += sdl

SOURCES += src/main.cpp \
    src/scroll_engine.cpp \
    src/surface.cpp \
    src/rgb.cpp \
    src/output.cpp \
    src/player_controller.cpp \
    src/aabb.cpp \
    src/sprite.cpp \
    src/entity.cpp \
    src/collidable.cpp \
    src/cell.cpp

HEADERS += \
    src/scroll_engine.h \
    src/surface.h \
    src/rgb.h \
    src/output.h \
    src/player_controller.h \
    src/aabb.h \
    src/sprite.h \
    src/entity.h \
    src/collidable.h \
    src/cell.h

