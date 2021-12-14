#include <string>

#include "level.hpp"
#include "vector_2d.h"
#include "images.h"
#include "player.hpp"

std::string level[LEVEL_HEIGHT];

char level_get(Vector2D pos)
{
    return level[pos.y][pos.x];
}

void level_set(Vector2D pos, char obj)
{
    level[pos.y][pos.x] = obj;
}

void level_delete(Vector2D pos)
{
    level_set(pos, SPACE_IMG);
}

void level_clear()
{
    for (size_t i = 0; i < LEVEL_HEIGHT; ++i)
    {
        level[i] = std::string(LEVEL_WIDTH, SPACE_IMG);
    }
}

bool level_is_equal(Vector2D pos, char obj)
{
    return level_get(pos) == obj;
}

void level_move(Vector2D pos, Vector2D delta)
{
    char obj = level_get(pos);
    level_delete(pos);
    Vector2D new_pos = {pos.x + delta.x, pos.y + delta.y};
    level_set(new_pos, obj);
}

void level_generate()
{
    srand(time(NULL));

    for (size_t y = 0; y < LEVEL_HEIGHT; ++y)
    {
        level[y] = std::string(LEVEL_WIDTH, SPACE_IMG);

        for (size_t x = 0; x < LEVEL_WIDTH; ++x)
        {
            // draw borders
            if ((x == 0)
                    || (y == 0)
                    || (x == (LEVEL_WIDTH - 1))
                    || (y == (LEVEL_HEIGHT - 1)))
            {
                level[y][x] = WALL_IMG;
            }

            else
            {
                int value = rand() % 12;

                switch (value)
                {
                    case 0:
                        level[y][x] =  WALL_IMG;
                        break;

                   case 1:
                        level[y][x] = STONE_IMG;
                        break;

                    default:
                        level[y][x] = SPACE_IMG;
                        break;
                }
            }
        }
    }
}

void level_add_randomly(char obj)
{
    int x = rand() % (LEVEL_WIDTH - 2) + 1;
    int y = rand() % (LEVEL_HEIGHT - 2) + 1;

    Vector2D pos = {x, y};

    level_set(pos, obj);
}
