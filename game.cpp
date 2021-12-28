#include <iostream>
#include <unistd.h>

#include "level.hpp"
#include "player.hpp"
#include "vector_2d.h"
#include "game_object_t.h"
#include "game_objects_list.h"
#include "input.hpp"
#include "enemy.h"
#include "algorithm.h"
#include "display.hpp"

void game_move_player()
{
    int key = get_key();

    vector_2d_t player_movement = {0, 0};

    switch (key)
    {
        case INPUT_ARROW_RIGHT:
        player_movement = {1, 0};
        break;

        case INPUT_ARROW_LEFT:
        player_movement = {-1, 0};
        break;

        case INPUT_ARROW_DOWN:
        player_movement = {0, 1};
        break;

        case INPUT_ARROW_UP:
        player_movement = {0, -1};
        break;
    }

    vector_2d_t player_new_pos = {player_pos.x + player_movement.x, player_pos.y + player_movement.y};

    char hit_obj_img= level_get(player_new_pos).image;

    if (hit_obj_img == SPACE_IMAGE)
    {
        level_move(player_pos, player_movement);
        player_move(player_movement);
    }

    else if(hit_obj_img == STONE_IMAGE)
    {
        Vector2D stone_new_pos = {player_new_pos.x + player_movement.x, player_new_pos.y + player_movement.y};
        if (level_get(stone_new_pos).image == SPACE_IMAGE)
        {
            level_move(player_new_pos, player_movement);
            level_move(player_pos, player_movement);
            player_move(player_movement);
        }
    }

    else if(hit_obj_img == COIN_IMAGE)
    {
        level_delete(player_new_pos);
        level_move(player_pos, player_movement);
        player_move(player_movement);
        player_add_coin();
    }

    else if(hit_obj_img == ENEMY_IMAGE)
    {
        player_is_alive = false;

    }
}

void game_move_enemies()
{
    for (size_t i = 0; i < enemies_count; ++i)
    {
        vector_2d_t new_enemy_pos =
        {
            enemies_pos[i].x + enemies_movement_directions[i].x,
            enemies_pos[i].y + enemies_movement_directions[i].y
        };

        if (level_get(new_enemy_pos).image == PLAYER_IMAGE)
        {
            player_is_alive = false;
            break;
        }

        else if (level_get(new_enemy_pos).image == SPACE_IMAGE)
        {
            level_move(enemies_pos[i], enemies_movement_directions[i]);
            enemy_move(enemies_movement_directions[i], i);
        }

        else
        {
            Vector2D movement_directions[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
            randomize_vector(movement_directions, 4);

            for (int j = 0; j < 4; ++j)
            {
                Vector2D enemy_pos_in_new_direction =
                {
                  enemies_pos[i].x + movement_directions[j].x,
                  enemies_pos[i].y + movement_directions[j].y
                };

                if (level_get(enemy_pos_in_new_direction).image == PLAYER_IMAGE)
                {
                    player_is_alive = false;
                    break;
                }

                else if (level_get(enemy_pos_in_new_direction).image == SPACE_IMAGE)
                {
                    enemies_movement_directions[i] = movement_directions[j];
                    break;
                }
            }
        }
    }
}

void game_add_enemies(size_t level_h, size_t level_w)
{
    enemies_pos = new vector_2d_t[enemies_count];
    enemies_movement_directions = new vector_2d_t[enemies_count];

    vector_2d_t movement_directions[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    for (size_t i = 0; i < enemies_count; ++i)
    {
        int value = rand() % 4;
        enemies_movement_directions[i] = movement_directions[value];

        int x = rand() % (level_w - 2) + 1;
        int y = rand() % (level_h - 2) + 1;

        while(level_get(x, y).image != SPACE_IMAGE)
        {
            x = rand() % (level_w - 2) + 1;
            y = rand() % (level_h - 2) + 1;
        }

        enemies_pos[i].x = x;
        enemies_pos[i].y = y;

        level_set(enemies_pos[i], ENEMY_GAME_OBJECT);
    }
}

void game_add_player(size_t level_h, size_t level_w)
{
    player_setup();

    int x = rand() % (level_w - 2) + 1;
    int y = rand() % (level_h - 2) + 1;

    while (level_get(x, y).image != SPACE_IMAGE)
    {
        x = rand() % (level_w - 2) + 1;
        y = rand() % (level_h - 2) + 1;
    }

    player_pos.x = x;
    player_pos.y = y;
    level_set(player_pos, PLAYER_GAME_OBJECT);
    player_is_alive = true;
}

void game_add_coins(size_t level_h, size_t level_w)
{
    for (size_t i = 0; i < player_coins_to_win; ++i)
    {
        int x = rand() % (level_w - 2) + 1;
        int y = rand() % (level_h - 2) + 1;

        while (level_get(x, y).image != SPACE_IMAGE)
        {
            x = rand() % (level_w - 2) + 1;
            y = rand() % (level_h - 2) + 1;
        }

        level_set(x, y, COIN_GAME_OBJECT);
    }
}

void game_over_screen()
{
    std::cout << "GAME OVER" << std::endl;
}

void game_passed_screen()
{
    std::cout << "GAME PASSED" << std::endl;
}

void game_end()
{
    if (player_is_alive)
    {
        game_passed_screen();
    }

    else
    {
        game_over_screen();
    }

    sleep(3);
}

void game_show_stat()
{
    std::cout << "Coins: " << player_collected_coins << "/" << player_coins_to_win << std::endl;
}

