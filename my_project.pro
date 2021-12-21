TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        algorithm.cpp \
        display.cpp \
        enemy.cpp \
        file_system.cpp \
        game.cpp \
        game_objects_list.cpp \
        input.cpp \
        level.cpp \
        main.cpp \
        menu.cpp \
        player.cpp \
        vector_2d.cpp

DISTFILES +=

HEADERS += \
    algorithm.h \
    colors.h \
    display.hpp \
    enemy.h \
    file_system.h \
    game.h \
    game_object_t.h \
    game_objects_list.h \
    images.h \
    input.hpp \
    level.hpp \
    menu.h \
    player.hpp \
    vector_2d.h
