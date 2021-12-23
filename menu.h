#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <vector>

struct MenuItem
{
    std::string name;
    bool (*handler)();
};

typedef struct MenuItem menu_item_t;

void menu_show(menu_item_t items[], size_t items_count, int cursor_pos);
void menu_show(std::vector<std::string> items, int cursor_pos);

bool menu_enter(menu_item_t items[], size_t size);
std::string menu_enter(std::vector<std::string> items);

#endif // MENU_H
