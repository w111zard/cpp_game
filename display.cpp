#include <string>
#include <iostream>

#include "display.hpp"
#include "game_object_t.h"
#include "level.hpp"

void display_level(std::vector<std::vector<game_object_t>> data)
{
   // Maximum level size is 75
   // Bigger level doesn't work correct

    for (size_t y = 0; y < data.size(); ++y)
   {
       for (size_t x = 0; x < data[y].size(); ++x)
       {
           std::cout << "\033[1;3"
                     << std::to_string(data[y][x].color)
                     << "m"
                     << char(data[y][x].image)
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
