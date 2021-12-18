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

int main()
{
    display_set_size(75, 120);
    srand(time(NULL));

    while (true)
    {
        size_t h, w, n;
        std::cout << "Level height: ";
        std::cin >> h;
        std::cout << "Level width: ";
        std::cin >> w;
        std::cout << "Enemies number: ";
        std::cin >> n;

        input_setup();

        // LEVEL SETUP
        level_set_size(h, w);
        level_create();
        level_generate();

        // GAME OBJECTS SETUP
        game_add_coins();

        enemies_set_count(n);
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
