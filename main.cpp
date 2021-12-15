#include <iostream>
#include <string>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "display.hpp"
#include "level.hpp"
#include "input.hpp"
#include "player.hpp"
#include "vector_2d.h"
#include "enemy.h"
#include "algorithm.h"
#include "game_objects_list.h"
#include "game_object_t.h"
#include "game.h"

int main()
{
    input_setup();
    srand(time(NULL));

    while (true)
    {
        level_generate();

        game_add_enemies();
        game_add_coins();
        game_add_player();

        display_level(level);

        // GAME PROCESS
        while (player_is_alive && (player_collected_coins < player_coins_to_win))
        {
            game_move_player();

            system("clear");
            display_level(level);
            game_show_stat();

            game_move_enemies();
        }

        game_end();
    }

    input_restore();

    return 0;
}
