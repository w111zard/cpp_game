#include <iostream>
#include <string>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <limits>

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

bool start_game()
{
    std::cout << "game started!!" << std::endl;
}

bool exit_game()
{
    exit(0);
}

int main()
{
    display_set_size(75, 120);
    srand(time(NULL));

    menu_item_t items[] =
    {
      {.name = "Start game", .handler = start_game},
      {.name = "Exit game", .handler = exit_game}
    };

    while (true)
    {
        input_setup();
        menu_main(items, 2);

        system("clear");

        input_restore();
        menu_settings(level_h, level_w, enemies_count);


        system("clear");

        input_setup();

        // LEVEL SETUP
        level_create();
        level_generate();

        // GAME OBJECTS SETUP
        game_add_coins();

        game_add_enemies();

        game_add_player();


        display_level(level, level_h, level_w);

        // GAME PROCESS
        while (player_is_alive && (player_collected_coins < player_coins_to_win))
        {
            game_move_player();

            system("clear");
            display_level(level, level_h, level_w);
            game_show_stat();

            game_move_enemies();
        }

        game_end();
        input_restore();
        level_free_memory();
        enemies_free_memory();
        system("clear");

        // CLEARING CIN BUFFER
        std::cout << "Press enter to continue..." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("clear");
    }

    return 0;
}
