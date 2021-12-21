#include <string>
#include <iostream>

#include "display.hpp"
#include "game_object_t.h"
#include "level.hpp"

void display_level(game_object_t **level, size_t h, size_t w)
{
   // Maximum level size is 75
   // Bigger level doesn't work correct

    for (size_t y = 0; y < h; ++y)
   {
       for (size_t x = 0; x < w; ++x)
       {
           std::cout << "\033[1;3"
                     << std::to_string(level[y][x].foreground_color)
                     << "m"
                     << char(level[y][x].image)
                     << " "
                     << "\033[0m";
       }


       std::cout << "\n";
   }
}

void display_set_size(size_t h, size_t w)
{
    std::cout << "\e[8;" << std::to_string(h) << ";" << std::to_string(w) << "t";
}
