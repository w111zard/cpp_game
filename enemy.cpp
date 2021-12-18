#include <cstdlib>

#include "enemy.h"
#include "vector_2d.h"

size_t enemies_count;
vector_2d_t *enemies_pos;
vector_2d_t *enemies_movement_directions;

void enemy_move(Vector2D delta, size_t enemy_index)
{
    enemies_pos[enemy_index].x += delta.x;
    enemies_pos[enemy_index].y += delta.y;
}

void enemies_set_count(size_t n)
{
    enemies_count = n;
}

void enemies_free_memory()
{
    delete[] enemies_pos;
    enemies_pos = nullptr;

    delete[] enemies_movement_directions;
    enemies_movement_directions = nullptr;
}
