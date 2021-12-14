#include "enemy.h"
#include "vector_2d.h"

const int ENEMIES_COUNT = 10;
Vector2D enemies_pos[ENEMIES_COUNT];
Vector2D enemies_movement_directions[ENEMIES_COUNT];

void enemy_move(Vector2D delta, int enemy_index)
{
    enemies_pos[enemy_index].x += delta.x;
    enemies_pos[enemy_index].y += delta.y;
}
