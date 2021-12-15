#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>

#include "vector_2d.h"

extern const size_t ENEMIES_COUNT;
extern vector_2d_t enemies_pos[];
extern vector_2d_t enemies_movement_directions[];

void enemy_move(Vector2D delta, size_t enemy_index);

#endif // ENEMY_H
