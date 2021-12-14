#include <string>

#include "level.hpp"
#include "vector_2d.h"
#include "game_object_t.h"
#include "game_objects_list.h"

game_object_t level[LEVEL_HEIGHT][LEVEL_WIDTH];

game_object_t level_get(Vector2D pos)
{
    return level[pos.y][pos.x];
}

void level_set(Vector2D pos, game_object_t obj)
{
    level[pos.y][pos.x] = obj;
}

void level_delete(Vector2D pos)
{
    level_set(pos, SPACE_OBJ);
}

void level_clear()
{
    for (int y = 0; y < LEVEL_HEIGHT; ++y)
    {
        for (int x = 0; x < LEVEL_WIDTH; ++x)
        {
            level_delete(Vector2D {x, y});
        }
    }
}

bool level_is_equal(Vector2D pos, game_object_t obj)
{
    return level_get(pos).img == obj.img;
}

void level_move(Vector2D pos, Vector2D delta)
{
    game_object_t obj = level_get(pos);
    level_delete(pos);
    Vector2D new_pos = {pos.x + delta.x, pos.y + delta.y};
    level_set(new_pos, obj);
}

void level_generate()
{
    srand(time(NULL));

    for (size_t y = 0; y < LEVEL_HEIGHT; ++y)
    {
        for (size_t x = 0; x < LEVEL_WIDTH; ++x)
        {
            // draw borders
            if ((x == 0)
                    || (y == 0)
                    || (x == (LEVEL_WIDTH - 1))
                    || (y == (LEVEL_HEIGHT - 1)))
            {
                level[y][x] = WALL_OBJ;
            }

            else
            {
                int value = rand() % 12;

                switch (value)
                {
                    case 0:
                        level[y][x] =  WALL_OBJ;
                        break;

                   case 1:
                        level[y][x] = STONE_OBJ;
                        break;

                    default:
                        level[y][x] = SPACE_OBJ;
                        break;
                }
            }
        }
    }
}

void level_add_randomly(game_object_t obj)
{
    int x = rand() % (LEVEL_WIDTH - 2) + 1;
    int y = rand() % (LEVEL_HEIGHT - 2) + 1;

    Vector2D pos = {x, y};

    level_set(pos, obj);
}
