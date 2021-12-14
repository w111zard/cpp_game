#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <string>
#include "vector_2d.h"
#include "game_object_t.h"

const int LEVEL_WIDTH = 40;
const int LEVEL_HEIGHT = 40;

extern game_object_t level[LEVEL_HEIGHT][LEVEL_WIDTH];

game_object_t level_get(Vector2D pos);
void level_set(Vector2D pos, game_object_t obj);
void level_delete(Vector2D pos);
void level_clear();
bool level_is_equal(Vector2D pos, game_object_t obj);
void level_move(Vector2D pos, Vector2D delta);
void level_generate();
void level_add_randomly(game_object_t obj);

#endif // LEVEL_HPP
