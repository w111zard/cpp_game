#include <string>

#include "level.hpp"
#include "vector_2d.h"
#include "game_object_t.h"
#include "game_objects_list.h"

game_object_t level[LEVEL_HEIGHT][LEVEL_WIDTH];

game_object_t level_get(vector_2d_t pos)
{
    return level[pos.y][pos.x];
}

void level_set(vector_2d_t pos, game_object_t obj)
{
    level[pos.y][pos.x] = obj;
}

void level_delete(Vector2D pos)
{
    level_set(pos, SPACE_GAME_OBJECT);
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

bool level_is_equal(vector_2d_t pos, game_object_t obj)
{
    return level_get(pos).image == obj.image;
}

void level_move(Vector2D pos, Vector2D delta)
{
    game_object_t obj = level_get(pos);
    level_delete(pos);
    vector_2d_t new_pos = {pos.x + delta.x, pos.y + delta.y};
    level_set(new_pos, obj);
}

void level_generate()
{
    srand(time(NULL));

    for (size_t y = 0; y < LEVEL_HEIGHT; ++y)
    {
        for (size_t x = 0; x < LEVEL_WIDTH; ++x)
        {
            vector_2d_t pos = {int(x), int(y)};

            // draw borders
            if ((pos.x == 0)
                    || (pos.y == 0)
                    || (pos.x == (LEVEL_WIDTH - 1))
                    || (pos.y == (LEVEL_HEIGHT - 1)))
            {
                //level_set(pos, WALL_GAME_OBJECT);
                level[y][x] = WALL_GAME_OBJECT;
            }

            else
            {
                int value = rand() % 12;

                switch (value)
                {
                    case 0:
                        //level_set(pos, WALL_GAME_OBJECT);
                        level[y][x] = WALL_GAME_OBJECT;
                        break;

                   case 1:
                        //level_set(pos, STONE_GAME_OBJECT);
                        level[y][x] = STONE_GAME_OBJECT;
                        break;

                    default:
                        //level_set(pos, SPACE_GAME_OBJECT);
                        level[y][x] = SPACE_GAME_OBJECT;
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
