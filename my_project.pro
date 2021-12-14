TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        algorithm.cpp \
        display.cpp \
        enemy.cpp \
        input.cpp \
        level.cpp \
        main.cpp \
        player.cpp \
        vector_2d.cpp

DISTFILES +=

HEADERS += \
    algorithm.h \
    colors.h \
    display.hpp \
    enemy.h \
    game_object_t.h \
    game_objects_list.h \
    images.h \
    input.hpp \
    level.hpp \
    player.hpp \
    vector_2d.h
