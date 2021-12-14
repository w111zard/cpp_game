#include <cstdlib>
#include <ctime>

#include "algorithm.h"
#include "vector_2d.h"

void randomize_vector(Vector2D *vector, size_t size)
{
    srand(time(NULL));

    for (size_t i = size - 1; i > 0; --i)
    {
        size_t j = rand() % i;
        Vector2D t = vector[i];
        vector[i] = vector[j];
        vector[j] = t;
    }
}
