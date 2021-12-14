#ifndef ENEMY_H
#define ENEMY_H

#include "vector_2d.h"

extern const int ENEMIES_COUNT;
extern Vector2D enemies_pos[];
extern Vector2D enemies_movement_directions[];

void enemy_move(Vector2D delta, int enemy_index);

#endif // ENEMY_H
