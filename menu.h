#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <vector>

void menu_show(std::vector<std::string> items, size_t selected_index);
void menu_cursor_move(int &cursor_position, size_t items_size, int delta);
std::string menu_enter(std::vector<std::string> items);


#endif // MENU_H
