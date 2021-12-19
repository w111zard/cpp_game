#include <string>
#include <iostream>

#include "menu.h"
#include "input.hpp"


void menu_show(menu_item_t items[], size_t items_count, int cursor_pos)
{
    for (size_t i = 0; i < items_count; ++i)
    {
        if (i == cursor_pos)
        {
            std::cout << ">" << items[i].name << "<" << std::endl;
        }

        else
        {
            std::cout << " " << items[i].name << std::endl;
        }
    }
}

bool menu_enter(menu_item_t items[], size_t size)
{
    int cursor_pos = 0;

    while (true)
    {
        menu_show(items, size, cursor_pos);

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
            if (cursor_pos + 1 < size)
            {
                ++cursor_pos;
            }
        }

        else if(key == INPUT_ENTER)
        {
            return items[cursor_pos].handler();
        }

        system("clear");
    }
}
