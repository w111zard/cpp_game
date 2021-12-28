#include <string>
#include <unistd.h>
#include <vector>

#include "level.hpp"
#include "vector_2d.h"
#include "game_object_t.h"
#include "game_objects_list.h"

std::vector<std::vector<game_object_t>> level;

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
    for (size_t y = 0; y < level.size(); ++y)
    {
        for (size_t x = 0; x < level[y].size(); ++x)
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

    size_t level_h = level.size(), level_w = level[0].size();

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
    int x = rand() % (level[0].size() - 2) + 1;
    int y = rand() % (level.size() - 2) + 1;

    Vector2D pos = {x, y};

    level_set(pos, obj);
}

bool level_load(std::vector<std::string> data)
{
    size_t data_h = data.size();

    if (data_h < 3)
    {
        return false;
    }

    size_t data_w = data[0].size();
    if (data_w < 3)
    {
        return false;
    }

    if ((data_h < 3) || (data_w < 3))
    {
        return false;
    }

    for (size_t i = 1; i < data_h; ++i)
    {
        if (data[i].length() != data_w)
        {
            return false;
        }
    }

    level_resize(data_h, data_w);

    for (size_t y = 0; y < data_h; ++y)
    {
        for (size_t x = 0; x < data_w; ++x)
        {
            char image = data[y][x];
            game_object_t obj;

            if (image == WALL_IMAGE)
            {
                obj = WALL_GAME_OBJECT;
            }

            else if (image == STONE_IMAGE)
            {
                obj = STONE_GAME_OBJECT;
            }

            else
            {
                obj = SPACE_GAME_OBJECT;
            }

            level[y][x] = obj;
        }
    }

    return true;
}

void level_resize(size_t height, size_t width)
{
    level.resize(height);

    for (size_t i = 0; i < height; ++i)
    {
        level[i].resize(width);
    }
}
