#include <string>
#include <unistd.h>

#include "level.hpp"
#include "vector_2d.h"
#include "game_object_t.h"
#include "game_objects_list.h"

game_object_t **level;
size_t level_h;
size_t level_w;

void level_set_size(size_t h, size_t w)
{
    level_h = h;
    level_w = w;
}


void level_create()
{
    level = new game_object_t*[level_h];

    for (size_t i = 0; i < level_h; ++i)
    {
        level[i] = new game_object_t[level_w];
    }
}

void level_free_memory()
{
    for (size_t i = 0; i < level_h; ++i)
    {
        delete[] level[i];
    }

    delete[] level;
    level = nullptr;
}


// LEVEL_GET
game_object_t level_get(vector_2d_t pos)
{
    return level[pos.y][pos.x];
}

game_object_t level_get(size_t x, size_t y)
{
    return level[y][x];
}

// LEVEL_SET
void level_set(vector_2d_t pos, game_object_t obj)
{
    level[pos.y][pos.x] = obj;
}

void level_set(size_t x, size_t y, game_object_t obj)
{
    level[y][x] = obj;
}


// LEVEL_FILL
void level_fill(game_object_t obj)
{
    for (size_t y = 0; y < level_h; ++y)
    {
        for (size_t x = 0; x < level_w; ++x)
        {
            level_set(x, y, obj);
        }
    }
}

// LEVEL_DELETE
void level_delete(Vector2D pos)
{
    level_set(pos, SPACE_GAME_OBJECT);
}

void level_delete(size_t x, size_t y)
{
    level_set(x, y, SPACE_GAME_OBJECT);
}

// LEVEL_CLEAR
void level_clear()
{
    level_fill(SPACE_GAME_OBJECT);
}

// LEVEL_IS_EQUAL
bool level_is_equal(vector_2d_t pos, game_object_t obj)
{
    return level_get(pos).image == obj.image;
}

bool level_is_equal(size_t x, size_t y, game_object_t obj)
{
    return level_get(x, y).image == obj.image;
}

// LEVEL_MOVE
void level_move(Vector2D pos, Vector2D delta)
{
    game_object_t obj = level_get(pos);
    level_delete(pos);
    vector_2d_t new_pos = {pos.x + delta.x, pos.y + delta.y};
    level_set(new_pos, obj);
}


// LEVEL_GENERATE
void level_generate()
{
    srand(time(NULL));

    for (size_t y = 0; y < level_h; ++y)
    {
        for (size_t x = 0; x < level_w; ++x)
        {

            // draw borders
            if ((x == 0)
                    || (y == 0)
                    || (x == (level_w - 1))
                    || (y == (level_h - 1)))
            {
                level_set(x, y, WALL_GAME_OBJECT);
            }

            else
            {
                int value = rand() % 12;

                switch (value)
                {
                    case 0:
                        level_set(x, y, WALL_GAME_OBJECT);
                        break;

                   case 1:
                        level_set(x, y, STONE_GAME_OBJECT);
                        break;

                    default:
                        level_set(x, y, SPACE_GAME_OBJECT);
                        break;
                }
            }
        }
    }
}


// LEVEL_ADD_RANDOMLY
void level_add_randomly(game_object_t obj)
{
    int x = rand() % (level_w - 2) + 1;
    int y = rand() % (level_h - 2) + 1;

    Vector2D pos = {x, y};

    level_set(pos, obj);
}

