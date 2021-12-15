#ifndef GAME_H
#define GAME_H

#include "level.hpp"
#include "player.hpp"
#include "vector_2d.h"
#include "game_object_t.h"
#include "game_objects_list.h"
#include "input.hpp"
#include "enemy.h"
#include "algorithm.h"

void game_move_player();
void game_move_enemies();
void game_add_player();
void game_add_enemies();
void game_add_coins();
void game_end();
void game_show_stat();

#endif // GAME_H
