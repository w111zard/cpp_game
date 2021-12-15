#include "game_object_t.h"
#include "images.h"
#include "colors.h"

game_object_t SPACE_GAME_OBJECT =
{
    SPACE_IMAGE,
    COLOR_BLACK,
    COLOR_BLACK
};

game_object_t WALL_GAME_OBJECT =
{
    WALL_IMAGE,
    COLOR_BLUE,
    COLOR_BLACK
};

game_object_t STONE_GAME_OBJECT =
{
    STONE_IMAGE,
    COLOR_WHITE,
    COLOR_BLACK
};

game_object_t COIN_GAME_OBJECT =
{
  COIN_IMAGE,
  COLOR_GREEN,
  COLOR_BLACK
};

game_object_t PLAYER_GAME_OBJECT =
{
    PLAYER_IMAGE,
    COLOR_RED,
    COLOR_BLACK
};

game_object_t ENEMY_GAME_OBJECT =
{
    ENEMY_IMAGE,
    COLOR_CYAN,
    COLOR_BLACK
};
