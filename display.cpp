#include <string>
#include <iostream>

#include "display.hpp"
#include "images.h"

void display_level(std::string *array, size_t row_size, size_t col_size)
{
   for (size_t y = 0; y < row_size; ++y)
   {
       for (size_t x = 0; x < col_size; ++x)
       {
           if (array[y][x] == PLAYER_IMG)
           {
               std::cout << "\033[1;31m" << array[y][x] << "\033[0m ";
           }
           else
           {
               std::cout << array[y][x] << " ";
           }
       }
       std::cout << std::endl;
   }
}
