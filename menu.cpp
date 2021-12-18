#include <string>
#include <iostream>

#include "menu.h"
#include "input.hpp"

void menu_show(std::string items[], size_t items_count, int cursor_pos)
{
    for (size_t i = 0; i < items_count; ++i)
    {
        if (i == cursor_pos)
        {
            std::cout << ">" << items[i] << "<" << std::endl;
        }

        else
        {
            std::cout << " " << items[i] << std::endl;
        }
    }
}

void menu_level_mod()
{
    while (true)
    {

    }
}

void menu_main()
{
    int cursor_pos = 0;
    const size_t items_count = 2;
    std::string items[items_count] =
    {
      "Start new game",
      "Exit"
    };

    while (true)
    {
        menu_show(items, items_count, cursor_pos);

        int key = get_key();

        if (key == INPUT_ARROW_UP)
        {
            if (cursor_pos - 1 >= 0)
            {
                --cursor_pos;
            }
        }

        else if(key == INPUT_ARROW_DOWN)
        {
            if (cursor_pos + 1 < items_count)
            {
                ++cursor_pos;
            }
        }

        else if(key == INPUT_ENTER)
        {
            if (cursor_pos == 0)
            {
                return;
            }

            else
            {
                // close terminal
                // [doesn't work]
                exit(0);
            }
        }

        system("clear");
    }
}

void menu_settings(size_t &level_h, size_t &level_w, size_t &enemies_count)
{
    std::cout << "Enter level height: ";
    std::cin >> level_h;
    std::cout << "Enter level width: ";
    std::cin >> level_w;
    std::cout << "Enter enemies count: ";
    std::cin >> enemies_count;
}
