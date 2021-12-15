#include <cstdlib>

#include "enemy.h"
#include "vector_2d.h"

const size_t ENEMIES_COUNT = 10;
vector_2d_t enemies_pos[ENEMIES_COUNT];
vector_2d_t enemies_movement_directions[ENEMIES_COUNT];

void enemy_move(Vector2D delta, size_t enemy_index)
{
    enemies_pos[enemy_index].x += delta.x;
    enemies_pos[enemy_index].y += delta.y;
}
