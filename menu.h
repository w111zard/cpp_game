#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>

struct MenuItem
{
    std::string name;
    bool (*handler)();
};

typedef struct MenuItem menu_item_t;

void menu_show(menu_item_t items[], size_t items_count, int cursor_pos);
bool menu_enter(menu_item_t items[], size_t size);

#endif // MENU_H
