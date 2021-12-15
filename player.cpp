#include <string>
#include <iostream>

#include "player.hpp"
#include "vector_2d.h"

// player coordinates
Vector2D player_pos = {3, 3};

size_t player_collected_coins = 0;
size_t player_coins_to_win = 10;

bool player_is_alive;

void player_move(Vector2D delta)
{
    player_pos.x += delta.x;
    player_pos.y += delta.y;
}

void player_add_coin()
{
    ++player_collected_coins;
}

void player_setup()
{
    player_is_alive = true;

    player_collected_coins = 0;
}
