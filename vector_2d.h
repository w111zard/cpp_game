#ifndef VECTOR_2D_H
#define VECTOR_2D_H

struct Vector2D
{
    int x;
    int y;
};

typedef Vector2D vector_2d_t;

Vector2D *vector_get_movement_directions();

#endif // VECTOR_2D_H
