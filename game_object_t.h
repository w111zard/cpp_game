#ifndef GAME_OBJECT_T_H
#define GAME_OBJECT_T_H

#include <string>

#include "images.h"
#include "colors.h"

struct GameObject
{
    char image;
    int color;
};

typedef GameObject game_object_t;

#endif // GAME_OBJECT_T_H
