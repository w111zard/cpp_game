#include <string>
#include <iostream>

#include "display.hpp"
#include "game_object_t.h"
#include "level.hpp"

void display_level(game_object_t level[LEVEL_HEIGHT][LEVEL_WIDTH])
{
   for (size_t y = 0; y < LEVEL_HEIGHT; ++y)
   {
       for (size_t x = 0; x < LEVEL_WIDTH; ++x)
       {
           std::cout << "\033[1;3";
           std::cout << std::to_string(level[y][x].foreground_color);
           std::cout << "m";
           std::cout << char(level[y][x].image);
           std::cout << "\033[0m ";

       }

       std::cout << std::endl;
   }
}
