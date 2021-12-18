#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>

#include "vector_2d.h"

extern size_t enemies_count;
extern vector_2d_t *enemies_pos;
extern vector_2d_t *enemies_movement_directions;

void enemy_move(Vector2D delta, size_t enemy_index);
void enemies_set_count(size_t n);
void enemies_free_memory();

#endif // ENEMY_H
