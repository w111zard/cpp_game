#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <string>
#include "vector_2d.h"
#include "game_object_t.h"

extern game_object_t **level;

extern size_t level_h;
extern size_t level_w;

void level_set_size(size_t h, size_t w);
void level_create();
void level_free_memory();

game_object_t level_get(vector_2d_t pos);
game_object_t level_get(size_t x, size_t y);

void level_set(vector_2d_t pos, game_object_t obj);
void level_set(size_t x, size_t y, game_object_t obj);

void level_delete(vector_2d_t pos);
void level_delete(size_t x, size_t y);

void level_clear();

bool level_is_equal(vector_2d_t pos, game_object_t obj);
bool level_is_equal(size_t x, size_t y, game_object_t obj);

void level_move(vector_2d_t pos, vector_2d_t delta);

void level_generate();

void level_add_randomly(game_object_t obj);

void level_fill(game_object_t obj);

#endif // LEVEL_HPP
