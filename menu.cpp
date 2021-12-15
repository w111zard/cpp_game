#include <iostream>
#include <string>

#include "menu.h"

const size_t MENU_ELEMS_COUNT = 2;

std::string menu_elems[MENU_ELEMS_COUNT] =
{
    "New Game",
    "Exit"
};

int menu_cursor_pos = 0;

void menu_show()
{
    for (size_t elem = 0; elem < MENU_ELEMS_COUNT; ++elem)
    {
        if (elem == menu_cursor_pos)
        {
            std::cout << ">" << menu_elems[elem] << "<" << std::endl;
        }

        else
        {
            std::cout << " " << menu_elems[elem] << " " << std::endl;
        }
    }
}

void menu_cursor_down()
{
    if (menu_cursor_pos + 1 < MENU_ELEMS_COUNT)
    {
        ++menu_cursor_pos;
    }

    else
    {
        menu_cursor_pos = 0;
    }
}

void menu_cursor_up()
{
    if (menu_cursor_pos - 1 >= 0)
    {
        --menu_cursor_pos;
    }

    else
    {
        menu_cursor_pos = MENU_ELEMS_COUNT - 1;
    }
}
