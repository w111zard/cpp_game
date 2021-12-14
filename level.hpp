#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <string>
#include "vector_2d.h"

const int LEVEL_WIDTH = 40;
const int LEVEL_HEIGHT = 40;

extern std::string level[LEVEL_HEIGHT];
extern std::string clear_level[LEVEL_HEIGHT];

char level_get(Vector2D pos);
void level_set(Vector2D pos, char obj);
void level_delete(Vector2D pos);
void level_clear();
bool level_is_equal(Vector2D pos, char obj);
void level_move(Vector2D pos, Vector2D delta);
void level_generate();
void level_add_randomly(char obj);

#endif // LEVEL_HPP
