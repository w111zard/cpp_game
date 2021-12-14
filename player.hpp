#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "vector_2d.h"

// player coordinates
extern Vector2D player_pos;

extern int player_collected_coins;
extern int player_coins_to_win;


extern bool player_is_alive;

void player_move(Vector2D delta);
void player_add_coin();
void player_setup();

#endif // PLAYER_HPP
