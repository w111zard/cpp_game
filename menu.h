#ifndef MENU_H
#define MENU_H

#include <cstdlib>
#include <string>

extern const size_t MENU_ELEMS_COUNT;

extern std::string menu_elems[];

extern int menu_cursor_pos;

void menu_show();
void menu_cursor_down();
void menu_cursor_up();

#endif // MENU_H
