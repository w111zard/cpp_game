#include <iostream>
#include <string>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "display.hpp"
#include "level.hpp"
#include "input.hpp"
#include "player.hpp"
#include "vector_2d.h"
#include "enemy.h"
#include "algorithm.h"
#include "game_objects_list.h"
#include "game_object_t.h"

int main()
{
    input_setup();

    level_generate();

    display_level(level);

    std::cout << "Here" << std::endl;

    sleep(10000);

//    while (true)
//    {
//        system("clear");

//        level_generate();

//        srand(time(NULL));

//        // ENEMIES SETUP
//        Vector2D movement_directions[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

//        for (size_t i = 0; i < ENEMIES_COUNT; ++i)
//        {
//            int value = rand() % 4;
//            enemies_movement_directions[i] = movement_directions[value];

//            int x = rand() % (LEVEL_WIDTH - 2) + 1;
//            int y = rand() % (LEVEL_HEIGHT - 2) + 1;

//            enemies_pos[i].x = x;
//            enemies_pos[i].y = y;

//            level_set(enemies_pos[i], ENEMY_OBJ);
//        }


//        // PLAYER SETUP
//        player_setup();

//        int x = rand() % (LEVEL_WIDTH - 2) + 1;
//        int y = rand() % (LEVEL_HEIGHT - 2) + 1;
//        player_pos.x = x;
//        player_pos.y = y;
//        level_set(player_pos, PLAYER_OBJ);
//        player_is_alive = true;

//        // ADD COINS
//        for (size_t i = 0; i < player_coins_to_win; ++i)
//        {
//            level_add_randomly(COIN_OBJ);
//        }

//        display_level(level);

//        while (player_is_alive && (player_collected_coins < player_coins_to_win))
//        {
//            int key = get_key();

//            Vector2D player_movement = {0, 0};
//            switch (key)
//            {
//                case INPUT_ARROW_RIGHT:
//                player_movement = {1, 0};
//                break;

//                case INPUT_ARROW_LEFT:
//                player_movement = {-1, 0};
//                break;

//                case INPUT_ARROW_DOWN:
//                player_movement = {0, 1};
//                break;

//                case INPUT_ARROW_UP:
//                player_movement = {0, -1};
//                break;
//            }


//            // MOVE PLAYER
//            Vector2D player_new_pos = {player_pos.x + player_movement.x, player_pos.y + player_movement.y};

//            game_object_t hit_obj= level_get(player_new_pos);
//            if (hit_obj.img == SPACE_OBJ.img)
//            {
//                level_move(player_pos, player_movement);
//                player_move(player_movement);
//            }

//            else if(hit_obj.img == STONE_OBJ.img)
//            {
//                Vector2D stone_new_pos = {player_new_pos.x + player_movement.x, player_new_pos.y + player_movement.y};
//                if (level_get(stone_new_pos).img == SPACE_OBJ.img)
//                {
//                    level_move(player_new_pos, player_movement);
//                    level_move(player_pos, player_movement);
//                    player_move(player_movement);
//                }
//            }

//            else if(hit_obj.img == COIN_OBJ.img)
//            {
//                level_delete(player_new_pos);
//                level_move(player_pos, player_movement);
//                player_move(player_movement);
//                player_add_coin();
//            }

//            else if(hit_obj.img == ENEMY_OBJ.img)
//            {
//                player_is_alive = false;

//            }

//            system("clear");
//            display_level(level);
//            std::cout << "Coins: " << player_collected_coins << "/" << player_coins_to_win << std::endl;

//            // MOVE ENEMIES

//            for (size_t i = 0; i < ENEMIES_COUNT; ++i)
//            {
//                Vector2D new_enemy_pos =
//                {
//                    enemies_pos[i].x + enemies_movement_directions[i].x,
//                    enemies_pos[i].y + enemies_movement_directions[i].y
//                };

//                if (level_get(new_enemy_pos).img == PLAYER_OBJ.img)
//                {
//                    player_is_alive = false;
//                    break;
//                }

//                else if (level_get(new_enemy_pos).img == SPACE_OBJ.img)
//                {
//                    level_move(enemies_pos[i], enemies_movement_directions[i]);
//                    enemy_move(enemies_movement_directions[i], i);
//                }

//                else
//                {
//                    Vector2D movement_directions[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
//                    randomize_vector(movement_directions, 4);

//                    for (int j = 0; j < 4; ++j)
//                    {
//                        Vector2D enemy_pos_in_new_direction =
//                        {
//                          enemies_pos[i].x + movement_directions[j].x,
//                          enemies_pos[i].y + movement_directions[j].y
//                        };

//                        if (level_get(enemy_pos_in_new_direction).img == PLAYER_OBJ.img)
//                        {
//                            player_is_alive = false;
//                            break;
//                        }

//                        else if (level_get(enemy_pos_in_new_direction).img == SPACE_OBJ.img)
//                        {
//                            enemies_movement_directions[i] = movement_directions[j];
//                            break;
//                        }
//                    }
//                }
//            }
//        }

//        system("clear");
//        if (player_is_alive)
//        {
//            std::cout << "YOU WIN!" << std::endl;
//        }

//        else
//        {
//            std::cout << "GAME OVER" << std::endl;
//        }

//        sleep(3);
//    }

    input_restore();

    return 0;

}
