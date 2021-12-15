#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

#include "level.hpp"

void display_level(game_object_t level[LEVEL_HEIGHT][LEVEL_WIDTH]);
void display_set_size(size_t h, size_t w);

#endif // DISPLAY_HPP
