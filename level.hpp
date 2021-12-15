#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <string>
#include "vector_2d.h"
#include "game_object_t.h"

const int LEVEL_WIDTH = 35;
const int LEVEL_HEIGHT = 35;

extern game_object_t level[LEVEL_HEIGHT][LEVEL_WIDTH];

game_object_t level_get(vector_2d_t pos);
void level_set(vector_2d_t pos, game_object_t obj);
void level_delete(vector_2d_t pos);
void level_clear();
bool level_is_equal(vector_2d_t pos, game_object_t obj);
void level_move(vector_2d_t pos, vector_2d_t delta);
void level_generate();
void level_add_randomly(game_object_t obj);

#endif // LEVEL_HPP
