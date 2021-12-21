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
    input_setup();
    system("clear");

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

bool exit_game()
{
    exit(0);
}

bool genereate_random_level()
{
    input_restore();
    system("clear");

    std::cout << "Level height: ";
    std::cin >> level_h;

    std::cout << "Level width: ";
    std::cin >> level_w;

    std::cout << "Enemies count: ";
    std::cin >> enemies_count;

    level_create();
    level_generate();

    return start_game();
}

bool load_level_from_file()
{
    input_restore();
    system("clear");

    std::cout << "File name: ";
    std::string file_name;
    std::cin >> file_name;

    return start_game();
}

bool level_setup()
{
    menu_item_t menu_level_setup_items[] =
    {
     {.name = "Genereate random level", .handler = genereate_random_level},
     {.name = "Load level from file", .handler = load_level_from_file}
    };

    menu_enter(menu_level_setup_items, 2);
}

int main()
{
    display_set_size(150, 150);
    srand(time(NULL));

    menu_item_t menu_main_items[] =
    {
      {.name = "New game", .handler = level_setup},
      {.name = "Exit game", .handler = exit_game}
    };

    input_setup();

    while (true)
    {
        menu_enter(menu_main_items, 2);
    }

    return 0;
}
