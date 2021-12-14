#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include "game_object_t.h"

const game_object_t SPACE_OBJ = {' ', "\033[1;31m \033[0m"};
const game_object_t PLAYER_OBJ = {'x', "\037[1;31mx\033[0m"};
const game_object_t WALL_OBJ = {'#', "\033[1;34m#\033[0m"};
const game_object_t STONE_OBJ = {'@', "\033[1;31m@\033[0m"};
const game_object_t ENEMY_OBJ = {'!', "\031[1;31m!\033[0m"};
const game_object_t COIN_OBJ = {'$', "\036[1;31m$\033[0m"};

#endif // GAME_OBJECTS_H
