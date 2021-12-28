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

void start_game();

int main()
{
    display_set_size(50, 100);
    srand(time(NULL));

    while (true)
    {
        system("clear");

        menu_items = {"Play", "Exit"};

        std::string menu_selected_items = menu_enter(menu_items);

        // play
        if (menu_selected_items == menu_items[0])
        {
            menu_items  = {"Generate New Level", "Load Level From File"};

            std::string menu_selected_item = menu_enter(menu_items);

            // genereate new level
            if (menu_selected_item == menu_items[0])
            {
                system("clear");
                input_restore();

                size_t level_h, level_w;

                std::cout << "Level height: ";
                std::cin >> level_h;

                std::cout << "Level width: ";
                std::cin >> level_w;

                level_resize(level_h, level_w);

                level_generate();
            }

            // load level from file
            else if (menu_selected_item == menu_items[1])
            {
                // argument "." means that we use current directory
                std::vector<std::string> files_list = get_files(".");

                while (true)
                {
                    system("clear");
                    input_setup();

                    std::string file_name = menu_enter(files_list);

                    std::vector<std::string> file_data = file_system_read(file_name);

                    if (level_load(file_data))
                    {
                        start_game();
                    }

                    else
                    {
                        input_restore();
                        std::cout << "Error: can't open the file " << file_name << std::endl;
                        std::cout << "Press any  key to repeat..." << std::endl;
                        get_key();
                    }
                }
            }

            start_game();
        }

        // exit
        else if(menu_selected_items == menu_items[1])
        {
            exit(0);
        }
    }

    return 0;
}

void start_game()
{
    system("clear");
    input_restore();

    std::cout << "Enemies count: ";
    std::cin >> enemies_count;

    input_setup();
    system("clear");

    // GAME OBJECTS SETUP
    game_add_coins(level.size(), level[0].size());

    game_add_enemies(level.size(), level[0].size());

    game_add_player(level.size(), level[0].size());


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
    input_restore();
    enemies_free_memory();
    system("clear");

    // CLEARING CIN BUFFER
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("clear");
}
