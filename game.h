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
void game_add_player(size_t, size_t);
void game_add_enemies(size_t, size_t);
void game_add_coins(size_t, size_t);
void game_end();
void game_show_stat();
void game_passed_screen();
void game_over_screen();

#endif // GAME_H
