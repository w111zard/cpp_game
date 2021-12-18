#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>

void menu_show(std::string menu_layer[], size_t layer_size);
void menu_main();
void menu_settings(size_t &level_h, size_t &level_w, size_t &enemies_count);

#endif // MENU_H
