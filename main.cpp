#include <iostream>
#include <string>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <limits>
#include <fstream>
#include <vector>

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
#include "file_system.h"

bool start_game();
bool exit_game();
bool genereate_random_level();
bool load_level_from_file();
bool level_setup();

int main()
{
    display_set_size(50, 100);
    srand(time(NULL));

    menu_item_t menu_main_items[] =
    {
      {.name = "New game", .handler = level_setup},
      {.name = "Exit game", .handler = exit_game}
    };

    while (true)
    {
        input_setup();
        system("clear");
        menu_enter(menu_main_items, 2);
    }

    return 0;
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

bool load_level_from_file()
{
    system("clear");

    std::vector<std::string> files;

    // argument "." means that we use current directory
    files = get_files(".");

    std::string selected_file = menu_enter(files);

    std::ifstream in(selected_file); // open file


    std::string line;


    size_t file_h = 0, file_w = 0;
    if (in.is_open())
    {
        getline(in, line);
        file_w = line.length();

        if (file_w < 3) // expection error
        {
            std::cout << "Error: Level width must be > 3" << std::endl;
            sleep(3);
            return load_level_from_file();
        }

        in.seekg(0);
        while (getline(in, line))
        {
            if (line.length() != file_w)
            {
                std::cout << "Error: level width must be same in all rows" << std::endl;
                sleep(3);
                return load_level_from_file();
            }
            ++file_h;
        }

        if (file_h < 3)
        {
            std::cout << "Error: level height must be > 3" << std::endl;
            sleep(3);
            return load_level_from_file();
        }

        level_h = file_h;
        level_w = file_w;

        level_create();

        in.clear();
        in.seekg(0);
        for (size_t y = 0; y < level_h; ++y)
        {
            getline(in, line);

            for (size_t x = 0; x < level_w; ++x)
            {
               char file_img = line[x];
               game_object_t obj;

               if (file_img == WALL_IMAGE)
               {
                   obj = WALL_GAME_OBJECT;
               }

               else if(file_img == STONE_IMAGE)
               {
                   obj = STONE_GAME_OBJECT;
               }

               else
               {
                   obj = SPACE_GAME_OBJECT;
               }

               level[y][x] = obj;
            }
        }
    }

    else
    {
        std::cout << "Error: can't open the file. Try again after 3 seconds..." << "\n";
        sleep(3);
        return load_level_from_file();
    }

    in.close();     // close file

    return start_game();
}

bool genereate_random_level()
{
    input_restore();
    system("clear");

    std::cout << "Level height: ";
    std::cin >> level_h;

    if (level_h < 3 || level_h > 75)
    {
        std::cout << "Error: uncorrect level size" << std::endl;
        sleep(3);
        return genereate_random_level();
    }

    std::cout << "Level width: ";
    std::cin >> level_w;

    if (level_w < 3 || level_w > 75)
    {
        std::cout << "Error: uncorrect level size" << std::endl;
        sleep(3);
        return genereate_random_level();
    }

    level_create();
    level_generate();

    return start_game();
}

bool exit_game()
{
    exit(0);
}

bool start_game()
{
    input_restore();
    system("clear");

    std::cout << "Enemies count: ";
    std::cin >> enemies_count;

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
