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
#include "menu.h"

int main()
{
    display_set_size(45, 75);
    input_setup();
    srand(time(NULL));


    while (true)
    {
        // MENU
        bool is_game_on = false;
        while (!is_game_on)
        {
            menu_show();

            int key = get_key();

            if (key == INPUT_ARROW_UP)
            {
                menu_cursor_up();
            }

            else if (key == INPUT_ARROW_DOWN)
            {
                menu_cursor_down();
            }

            else if (key == INPUT_ENTER)
            {
                if (menu_cursor_pos == 0)
                {
                    is_game_on = true;
                }

                else if (menu_cursor_pos == 1)
                {
                    return 0;
                }
            }

            std::cout << key << std::endl;

            system("clear");
        }

        // GAME SETUP
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
