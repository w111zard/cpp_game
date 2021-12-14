#include "vector_2d.h"

Vector2D *vector_get_movement_directions()
{
    Vector2D movement_directions[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    return movement_directions;
}
