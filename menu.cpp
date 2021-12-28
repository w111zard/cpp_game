 #include <string>
#include <iostream>
#include <vector>

#include "menu.h"
#include "input.hpp"

void menu_show(std::vector<std::string> items, size_t selected_index)
{
    for (size_t i = 0; i < items.size(); ++i)
    {
        if (i ==  selected_index)
        {
            std::cout << ">" << items[i] << "<" << std::endl;
        }

        else
        {
            std::cout << items[i] << std::endl;
        }
    }
}

void menu_cursor_move(size_t &cursor_position, size_t items_size, int delta)
{
    if (delta == -1)
    {
        if (cursor_position == 0)
        {
            cursor_position = items_size - 1;
        }

        else
        {
            --cursor_position;
        }
    }

    else
    {
        if (cursor_position == items_size - 1)
        {
            cursor_position = 0;
        }

        else
        {
            ++cursor_position;
        }
    }
}

std::string menu_enter(std::vector<std::string> items)
{
    size_t selected_index = 0;

    if (!INPUT_SETUP_FLAG)
    {
        input_setup();
    }

    while (true)
    {
        menu_show(items, selected_index);

        int key = get_key();

        switch (key)
        {
            case INPUT_ARROW_UP:
            {
                menu_cursor_move(selected_index, items.size(), -1);
                break;
            }

            case INPUT_ARROW_DOWN:
            {
               menu_cursor_move(selected_index, items.size(), 1);
               break;
            }

            case INPUT_ENTER:
            {
                return items[selected_index];
            }
        }

        system("clear");
    }
}
